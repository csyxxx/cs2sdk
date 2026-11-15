"""Build with a case-normalized Windows environment (avoids Path/PATH clashes)."""
import argparse
import os
from pathlib import Path
import shutil
import subprocess
import sys

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('configuration', nargs='?', choices=['Development', 'Ship'], default='Development')
parser.add_argument('--msbuild', type=Path)
args = parser.parse_args()
root = Path(__file__).resolve().parents[1]
msbuild = args.msbuild or shutil.which('MSBuild.exe')
if not msbuild:
    vswhere = Path(os.environ.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Microsoft Visual Studio/Installer/vswhere.exe'
    if vswhere.exists():
        found = subprocess.check_output([str(vswhere), '-latest', '-products', '*', '-requires', 'Microsoft.Component.MSBuild', '-find', r'MSBuild\**\Bin\MSBuild.exe'], text=True).splitlines()
        msbuild = found[0] if found else None
if not msbuild:
    sys.exit('MSBuild not found; run in Developer PowerShell or pass --msbuild <path>.')
environment = {key.upper(): value for key, value in os.environ.items()}
log = root / f'build-{args.configuration.lower()}.log'
command = [str(msbuild), str(root / 'cs2sdk.slnx'), '/t:Build',
           f'/p:Configuration={args.configuration}', '/p:Platform=x64', '/m', '/v:minimal',
           '/clp:ErrorsOnly', '/fl', f'/flp:logfile={log};verbosity=normal']
result = subprocess.run(command, cwd=root, env=environment, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
output = result.stdout.decode('mbcs', errors='replace')
errors = list(dict.fromkeys(line for line in output.splitlines() if 'error' in line.lower()))
for line in errors[:40]:
    print(line)
print(f'{args.configuration}: exit code {result.returncode}; log: {log}')
if result.returncode == 0:
    print(f'DLL: {root / "bin" / args.configuration / "cs2sdk.dll"}')
sys.exit(result.returncode)
