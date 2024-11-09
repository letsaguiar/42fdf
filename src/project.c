#include "fdf.h"
#include <math.h>

void    project(t_screen *screen, t_point *point, int offset_x, int offset_y)
{
    float angle = screen->angle;

    // Store original x and y to avoid overwriting values
    int original_x = point->x;
    int original_y = point->y;

    // Apply isometric projection
    point->x = original_x * cos(angle) - original_y * cos(angle);
    point->y = original_x * sin(angle) + original_y * sin(angle) - point->z;

    // Translate the origin to the center of the screen
    point->x += offset_x;
    point->y += offset_y;
}