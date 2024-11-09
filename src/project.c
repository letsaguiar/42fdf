#include "fdf.h"
#include <math.h>

void    project(t_screen *screen, t_point *point, int offset_x, int offset_y)
{
    float angle_x = screen->x_angle;
    float angle_y = screen->y_angle;

    // Store original x and y to avoid overwriting values
    int original_x = point->x;
    int original_y = point->y;

    // Apply isometric projection
    point->x = original_x * cos(angle_x) - original_y * cos(angle_x);
    point->y = original_x * sin(angle_y) + original_y * sin(angle_y) - point->z;

    // Translate the origin to the center of the screen
    point->x += offset_x;
    point->y += offset_y;
}