@set PATH=C:\MinGW\mingw64\bin;%PATH%

g++ lib\lib.cpp -shared -o bin\libmatrix.dll

g++ -Ilib -Lbin -lmatrix app\app.cpp -o bin\app.exe
