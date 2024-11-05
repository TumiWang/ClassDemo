@echo off

@REM 该文件因为有中文所以使用了UTF8编码
@REM 但Windows默认适用的时本地编码 例如 简体中文使用的时GB2312
@REM 故使用下面命令切换到UTF8的页面编码

for /f "tokens=2 delims=:" %%a in ('chcp') do set CODEPAGE=%%a
IF %CODEPAGE% neq 65001 (
    CHCP 65001
)

@REM 除了编码外，BAT文件的换行一定要使用CRLF

CD /d %~dp0

SET SCRIPT_DIR=$CD$
SET PRUDOCT_DIR=product
SET BUILD_DIR=build
@REM SET VC_VERSION=Visual Studio 16 2019
SET VC_VERSION=Visual Studio 17 2022
@REM SET  BUILD_TYPE=Release
SET BUILD_TYPE=Debug
@REM SET ARCH_TYPE=win32
SET ARCH_TYPE=x64

IF EXIST "%BUILD_DIR%" (
    RMDIR /s /q "%BUILD_DIR%"
)

IF EXIST "%PRUDOCT_DIR%" (
    RMDIR /s /q "%PRUDOCT_DIR%"
)

IF "%1_x" == "_x" (
    cmake -B "%BUILD_DIR%" -S . -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=$BUILD_TYPE
    IF %ERRORLEVEL% neq 0 (
        echo cmake创建项目失败
        goto end
    )
    goto buildsource
)

IF "%2_x" == "_x" (
    if NOT EXIST ".\\complex\\%1\\CMakeLists.txt" (
        echo CMakeLists.txt文件不存在
        goto end
    )
    cmake -B "%BUILD_DIR%" -S  ".\\complex\\%1" -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=$BUILD_TYPE
    IF %ERRORLEVEL% neq 0 (
        echo cmake创建项目失败
        goto end
    )
    goto buildsource
)

IF "%3_x" == "_x" (
    cmake -B "%BUILD_DIR%" -S . -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DMYTARGET="test%1_%2"
    IF %ERRORLEVEL% neq 0 (
        echo cmake创建项目失败
        goto end
    )
    goto buildsource
) ELSE (
    echo 不支持三个及以上参数
    goto end
)

:buildsource
cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake编译失败
    goto end
)

cmake --install "%BUILD_DIR%" --config %BUILD_TYPE% --prefix "%PRUDOCT_DIR%"
IF %ERRORLEVEL% neq 0 (
    echo cmake安装失败
    goto end
)

:end
@REM 切换页面编码后可能导致中文的输出被清除。故，这里添加一个暂停命令
IF %CODEPAGE% neq 65001 (
    PAUSE
    CHCP %CODEPAGE%
)