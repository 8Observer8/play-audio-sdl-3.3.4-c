cmake -G "MinGW Makefiles" -S . -B dist/win ^
-DSDL3_DIR=H:/libs/SDL3-devel-3.3.4-mingw/lib/cmake/SDL3 ^
-DSDL3_mixer_DIR=H:/libs/SDL3_mixer-devel-3.1.0-mingw/lib/cmake/SDL3_mixer ^
-DCMAKE_BUILD_TYPE=Release
