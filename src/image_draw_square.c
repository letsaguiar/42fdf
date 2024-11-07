#include "fdf.h"
#include <math.h>

static void project(t_point *point, int x, int y, int z)
{
    point->x = (x * cos(M_PI / 6) - y * cos(M_PI / 6));
    point->y = (y * sin(M_PI / 6) + x * sin(M_PI / 6) - z);
}

void image_draw_square(t_image *image, t_point point, int color)
{
    t_point p1, p2, p3, p4;
    project(&p1, point.x, point.y, point.z);
    project(&p2, point.x + TILE_SIZE, point.y, point.z);
    project(&p3, point.x + TILE_SIZE, point.y + TILE_SIZE, point.z);
    project(&p4, point.x, point.y + TILE_SIZE, point.z);

    image_draw_line(image, p1, p2, color);
    image_draw_line(image, p2, p3, color);
    image_draw_line(image, p3, p4, color);
    image_draw_line(image, p4, p1, color);
}
