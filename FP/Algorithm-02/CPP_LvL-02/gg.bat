@echo off 
for /l %%x in (22, 1, 40) do ( 
mkdir "HW__%%x"
echo.> "HW__%%x\HW-%%x.cpp"
)