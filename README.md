# CS2 SDK 基础框架

从 `D:\velocity\Velocity-Fix-main (3)\Velocity-Fix-main` 提取，目标是保留开发新项目所需的底层框架。源目录没有修改。

保留 DLL 入口与诊断、地址与特征扫描、接口、Schema、实体缓存、本地玩家、输入命令、预测、骨骼、包围盒、命中盒、射线、材质、VPK 图标、模型预览，以及线程池、Steam 包装、数学与内存工具。

Hook 保留 JMP/trampoline、分配器、管理器和引擎回调原型。默认安装 Present、ResizeBuffers、FrameStageNotify、CreateMove、实体增删、RenderView、地图初始化/退出；其余引擎 detour 保留为透传实现，按需接入。源项目的 `parse_report_hit` 原型已有失效记录，仍保持禁用。

GUI 使用原项目的 **xdraw + xui / Direct3D 11**，包含字体、控件、动画、主题接口和配置序列化；原有功能菜单改为基础菜单。默认按 **Delete** 打开/关闭，可修改菜单键、保存/读取配置。新配置使用独立的 `HKCU\Software\cs2sdk\configs`，不会读取原项目配置。

`utilities/proto` 是原项目自定义的 protobuf 内存布局、消息访问、重复字段与命令序列化包装，包含 BaseUserCmd、CSGOUserCmd、InputHistory、Subtick 等；源项目没有独立的 `.proto` 或生成的 Google protobuf SDK，本次没有另行生成。

未迁入 ragebot、legitbot、antiaim、ESP、换肤、移动辅助、世界修改、粒子特效、VAC bypass 和相关设置/菜单/算法。原 Lua 引擎的业务绑定也未接入；随源项目复制的 Lua/sol2 依赖可供后续扩展，当前 DLL 只链接 FreeType。

## 构建

打开 [cs2sdk.slnx](cs2sdk.slnx)，使用 Visual Studio 的 C++ 工具、ClangCL 和 Windows SDK，平台选择 x64。项目保持源工程的 ClangCL 与静态 CRT 配置；依赖的 include、release 静态库和许可证已放在 `cs2sdk/dependencies/x64-windows-static`，默认构建无需联网或访问原项目。

在 Developer PowerShell 中运行：

```powershell
MSBuild.exe cs2sdk.slnx /t:Build /p:Configuration=Development /p:Platform=x64 /m
MSBuild.exe cs2sdk.slnx /t:Build /p:Configuration=Ship /p:Platform=x64 /m
```

也可使用 Python 3 包装脚本，它会处理本机 `Path`/`PATH` 重复环境变量的问题：

```powershell
python tools/build.py Development
python tools/build.py Ship
python tools/verify_framework.py
```

输出分别为 `bin/Development/cs2sdk.dll` 和 `bin/Ship/cs2sdk.dll`；两种配置使用独立的中间目录。`vcpkg.json` 用于重新获取 FreeType，当前工程直接引用随附依赖，不会自动执行 vcpkg 安装。

## 添加代码

| 路径 | 用途 |
| --- | --- |
| `cs2sdk/project/entry.cpp` | DLL 入口、初始化顺序、诊断 |
| `cs2sdk/project/core/hooks` | Hook 安装与引擎回调 |
| `cs2sdk/project/core/systems` | 游戏 SDK 系统 |
| `cs2sdk/project/utilities/proto` | protobuf 包装 |
| `cs2sdk/project/protection` | 原项目游戏地址、签名与偏移 |
| `cs2sdk/project/utilities/addresses` | 模块、全局对象、函数与接口 |
| `cs2sdk/project/core/rendering` | 渲染上下文、字体、基础菜单 |
| `cs2sdk/project/external/xdraw` | GUI / 绘制底层 |
| `cs2sdk/project/core/settings.hpp` | 新项目配置项 |
| `cs2sdk/project/core/features` | 新功能模块接口与注册入口 |

继承 `features::module`，在 `features::initialize()` 中添加 `modules.emplace_back(std::make_unique<your_module>())`。支持命令、帧阶段、绘制、菜单、游戏事件与地图生命周期回调。新增 `.cpp/.hpp` 时也要添加到 `.vcxproj`。

模块在安装 hook 前注册，此后保持模块列表不变。回调可能来自不同的游戏/渲染线程，共享状态由模块自行同步。`on_create_move()` 只有返回 `true` 才调用原输入包装的 `apply()` 更新命令及 CRC；默认没有任何模块，因此不会改写攻击、视角、移动或发包状态。`mouse_input` 仅保留底层鼠标增量包装，未默认安装对应输入事件 hook。

## 验证范围

已验证本机 Development 与 Ship 的 DLL 编译、链接，以及工程文件覆盖、项目内 include 和 hook 声明/实现检查。尚未加载到游戏中验证；地址、偏移、签名和引擎调用约定沿用源项目，需要针对实际游戏版本检查。没有提供经过验证的热卸载流程。
