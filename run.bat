@echo off
chcp 65001 >nul
cd /d "%~dp0"
if not exist students_g.exe (
    echo students_g.exe not found, building...
    gcc -finput-charset=UTF-8 -fexec-charset=UTF-8 -Wall -g students_g.c -o students_g.exe
    if errorlevel 1 (
        pause
        exit /b 1
    )
)
students_g.exe
echo.
pause
