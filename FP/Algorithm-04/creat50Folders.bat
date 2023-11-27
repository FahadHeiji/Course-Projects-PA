@echo off
for /L %%i in (1,1,50) do (
    mkdir "Problem__%%i"
    echo. > "Problem__%%i\Problem-.cpp"
    echo. > "Problem__%%i\Problem-S.cpp"
)
