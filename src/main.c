#include "raylib.h"
#include <stdio.h>

int main()
{
    InitWindow(100, 100, "anplicatie");
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    return 0;
}