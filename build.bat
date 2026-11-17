@echo off
chcp 65001 >nul
cd /d "%~dp0"
gcc -finput-charset=UTF-8 -fexec-charset=UTF-8 -Wall -g students_g.c -o students_g.exe
if errorlevel 1 (
    echo.
    echo Build failed.
    pause
    exit /b 1
)
echo.
echo Build succeeded: students_g.exe
pause
