#include <stdio.h>
#include "raylib.h"
 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 size = {15.0f, 30.0f};
    SetTargetFPS(60); 
    Color bkgCor = {196, 23, 23, 255};
    
    // Main game loop
    while (!WindowShouldClose())  
    {
      static float speed = 50.0f;
      if (IsKeyDown(KEY_D)&&(ballPosition.x+size.x)<=screenWidth) ballPosition.x += speed;
      if (IsKeyDown(KEY_A)&&(ballPosition.x) > 0) ballPosition.x -= speed;
      if (IsKeyDown(KEY_W)&&(ballPosition.y) > 0) ballPosition.y -= speed;
      if (IsKeyDown(KEY_S)&&(ballPosition.y+size.y)<=screenHeight) ballPosition.y += speed;
      printf("x = %f e y = %f\n", ballPosition.x, ballPosition.y);
      BeginDrawing();
 
            ClearBackground(BLACK);
            DrawText("move the ball with W A S D", 10, 10, 20, BLUE);
            DrawRectangleV(ballPosition, size, bkgCor);
 
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();       
    return 0;
}
