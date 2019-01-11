@echo off

set repqt=C:\AFPA\outils\Qt\5.11.1\mingw53_32\bin

set pathdll=^
build-dllcreer-Desktop_Qt_5_11_1_MinGW_32bit-Debug\debug;^
build-dlldessiner-Desktop_Qt_5_11_1_MinGW_32bit-Debug\debug

set path=%pathdll%;%repqt%;%path%
set repexec=build-gestion-Desktop_Qt_5_11_1_MinGW_32bit-Debug\debug
set exec=gestion.exe

echo "Lancement de l'application : %repexec%\/%exec%"
%repexec%\%exec%
