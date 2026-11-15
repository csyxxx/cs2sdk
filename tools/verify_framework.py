"""Check the extraction boundary, project file coverage, includes and hook APIs."""
from pathlib import Path
import re
import sys
import xml.etree.ElementTree as ET

root = Path(__file__).resolve().parents[1]
project = root / 'cs2sdk'
sources = project / 'project'
errors = []
ns = {'m': 'http://schemas.microsoft.com/developer/msbuild/2003'}
xml = ET.parse(project / 'cs2sdk.vcxproj')
listed = set()
for item in xml.findall('.//m:ClCompile', ns) + xml.findall('.//m:ClInclude', ns) + xml.findall('.//m:None', ns):
    name = item.get('Include')
    if not name:
        continue
    path = (project / name).resolve()
    listed.add(path)
    if not path.is_file():
        errors.append(f'Project references missing file: {name}')

files = [p for p in sources.rglob('*') if p.suffix in {'.cpp', '.c', '.h', '.hpp', '.inl'}]
for path in files:
    if path.resolve() not in listed:
        errors.append(f'File omitted from project: {path.relative_to(root)}')
    text = path.read_text(encoding='utf-8-sig', errors='replace')
    for delimiter, include in re.findall(r'^\s*#\s*include\s*([<"])([^">]+)[">]', text, re.M):
        if delimiter == '"' or include.startswith(('core/', 'utilities/', 'external/', 'protection/', 'pch/')):
            if not any(p.is_file() for p in (path.parent / include, sources / include, project / 'dependencies/x64-windows-static/include' / include)):
                errors.append(f'Unresolved local include: {path.relative_to(root)} -> {include}')

for name in ['combat', 'esp', 'world', 'movement', 'misc', 'changer']:
    if (sources / 'core/features' / name).exists():
        errors.append(f'Original feature directory retained: {name}')
for path in files:
    if 'external' in path.relative_to(sources).parts:
        continue
    text = path.read_text(encoding='utf-8-sig', errors='replace')
    if re.search(r'features::(?:combat|esp|world|movement|misc|changer)::|settings::g_|scripting::g_engine|core/features/(?:combat|esp|world|movement|misc|changer)/', text):
        errors.append(f'Original feature dependency retained: {path.relative_to(root)}')

header = (sources / 'core/hooks/hooks.hpp').read_text(encoding='utf-8')
implementation = (sources / 'core/hooks/impl/cheat.cpp').read_text(encoding='utf-8')
declarations = set(re.findall(r'^\s*static\s+[^;\n]+?\b(\w+)\s*\(', header, re.M))
definitions = set(re.findall(r'\bcheat::(\w+)\s*\(', implementation))
for name in sorted(declarations - definitions):
    errors.append(f'Hook declaration lacks implementation: {name}')
if 'void input::clear_attack' not in (sources / 'core/systems/impl/input.buttons.cpp').read_text(encoding='utf-8'):
    errors.append('Generic input cleanup implementation missing')
if errors:
    print('\n'.join(errors))
    sys.exit(1)
print(f'PASS: {len(files)} source/header files covered; local includes resolve; {len(declarations)} hook methods implemented; original feature dependencies absent.')
