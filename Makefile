#!/bin/bash

 x86_64-w64-mingw32-gcc src/main.c src/Doom_Raytracing.c -o RT.exe -I../include lib/libraylib.a -lopengl32 -lgdi32 -lwinmm -static
