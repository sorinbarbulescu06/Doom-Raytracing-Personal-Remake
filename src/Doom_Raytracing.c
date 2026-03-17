#include "Doom_Raytracing.h"

void Initialize(triangle **arrow)
{
    InitWindow(Screen_Width, Screen_Height, "Doom Raytracing");
    SetTargetFPS(FPS);
    triangle *Arrow = malloc(sizeof(triangle));
    Arrow->Xg = 400;
    Arrow->Yg = 400;
    Arrow->Radius = 30;
    Arrow->Angle = 180;
    Arrow->X_vel = 0;
    Arrow->Y_vel = 0;
    *arrow = Arrow;
}

void DrawArrow(triangle *arrow)
{
    Vector2 A = {
        arrow->Xg + arrow->Radius * cosf(arrow->Angle * DEG2RAD),
        arrow->Yg + arrow->Radius * sinf(arrow->Angle * DEG2RAD)
    };
    Vector2 B = {
        arrow->Xg + arrow->Radius * cosf((arrow->Angle + 150) * DEG2RAD),
        arrow->Yg + arrow->Radius * sinf((arrow->Angle + 150) * DEG2RAD)
    };
    Vector2 C = {
        arrow->Xg + arrow->Radius * cosf((arrow->Angle + 210) * DEG2RAD),
        arrow->Yg + arrow->Radius * sinf((arrow->Angle + 210) * DEG2RAD)
    };
    DrawTriangle(A, C, B, RED);
}

void CheckMove(triangle *arrow)
{
    if(IsKeyDown(KEY_W)){
        arrow->X_vel += speed * cosf(arrow->Angle * DEG2RAD);
        arrow->Y_vel += speed * sinf(arrow->Angle * DEG2RAD);
    }
    if(IsKeyDown(KEY_S)){
        arrow->X_vel -= speed * cosf(arrow->Angle * DEG2RAD);
        arrow->Y_vel -= speed * sinf(arrow->Angle * DEG2RAD);
    }
}

void Movepos(triangle *arrow)
{
    arrow->Xg += arrow->X_vel;
    arrow->X_vel *= Friction;
    arrow->Yg += arrow->Y_vel;
    arrow->Y_vel *= Friction;
}

void CheckMargin(triangle *arrow, Image map)
{
    Vector2 A = {
        arrow->Xg + arrow->Radius * cosf(arrow->Angle * DEG2RAD),
        arrow->Yg + arrow->Radius * sinf(arrow->Angle * DEG2RAD)
    };
   // if(wall(map, A.x, A.y) == 1){
    //}
}

void CheckRotation(triangle *arrow)
{
    if(IsKeyDown(KEY_RIGHT)) arrow->Angle += sensitivity;
    if(IsKeyDown(KEY_LEFT))  arrow->Angle -= sensitivity;
    if (arrow->Angle >= 360.0f) arrow->Angle -= 360.0f;
    if (arrow->Angle < 0.0f) arrow->Angle += 360.0f;
}

void Draw(triangle *arrow, Texture2D mazeVisual)
{
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    DrawTexture(mazeVisual, 0, 0, WHITE);
    DrawArrow(arrow);
    EndDrawing();
}