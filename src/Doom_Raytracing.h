#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <math.h>

#define Screen_Width 1280
#define Screen_Height 720
#define Perpendicular 90
#define FPS 60
#define sensitivity 3
#define speed 2
#define Friction 0.5

typedef struct triangle{
    float Xg, Yg, Radius;
    float Angle;
    float X_vel;
    float Y_vel;
}triangle;

void Initialize(triangle **arrow);
void Draw(triangle *arrow, Texture2D mazeVisual);
void DrawArrow(triangle *arrow);
void CheckRotation(triangle *arrow);
void CheckMove(triangle *arrow);
void Movepos(triangle *arrow);
void CheckMargin(triangle *arrow, Image map);