@echo off
set /p name="Enter ID: "

gcc "%name%.c" -o a
a.exe
del a.exe
echo.
pause