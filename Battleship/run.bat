@echo off
gcc main.c -o main
if %errorlevel% equ 0 (
    main.exe
) else (
    echo Ошибка компиляции
    pause
)