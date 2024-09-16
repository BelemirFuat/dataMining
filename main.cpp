#include <raylib.h> //may occur some problems so give attention here
#include <cstddef> // Add this line
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <cmath>
#include <iostream>
#include <iomanip>

const float minX = -20.0F;
const float maxX = 20.0F;
const float minY = -20.0F;
const float maxY = 20.0F;

Vector2 projectSampleToScreen(Vector2 sample)
{
    float nx = (sample.x - minX) / (maxX - minX);
    float ny = (sample.y - minY) / (maxY - minY);

    return CLITERAL(Vector2){
        .x = GetScreenWidth() * nx,
        .y = GetScreenHeight() - GetScreenHeight() * ny,
    };
}

typedef struct
{
    Vector2 *items;
    size_t count;
    size_t capacity;
} Samples;

/*
 * generates random number between (both included) min and max in flaot data type
 */
float randFloat(float min = 0.0F, float max = RAND_MAX)
{
    return (float)((float)rand()/(float)RAND_MAX)+(float)(rand()%(int)max+min);
}

void generateCluster(Vector2 center, float radius, size_t count, Samples *samples)
{
    for (size_t i = 0; i < count; ++i)
    {
        for (size_t j = 0; j < count; ++i)
        {
        }
    }
}

int main()
{
    srand(time(0));
    std::cout<<"Rand: "<<std::setprecision(5)<<randFloat()<<std::endl;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "K-Means");
    SetTargetFPS(60);
    SetWindowPosition((2360 - GetScreenWidth() / 2), 540 - GetScreenHeight() / 2);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_Q))
        {
            DrawText("Bastın knk", 0, 0, 20, RED);
            CloseWindow();
        }
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));
        Vector2 sample = {-10, -10};
        DrawCircleV(projectSampleToScreen(sample), 10, RED);
        DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10.0F, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}