#include "Doom_Raytracing.h"

int main()
{
    triangle *arrow;
    Initialize(&arrow);
    Image mazeLogic = LoadImage("maze.png"); 
    Texture2D mazeVisual = LoadTextureFromImage(mazeLogic);
    while(!WindowShouldClose()){
        CheckRotation(arrow);
        CheckMove(arrow);
        CheckMargin(arrow, mazeLogic);
        Movepos(arrow);
        Draw(arrow, mazeVisual);
    }
    return 0;
}