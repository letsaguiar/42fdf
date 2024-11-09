#include "fdf.h"
#include <math.h>

void    image_draw_line(t_screen *screen, t_image *image, t_point p1, t_point p2, int color)
{
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = p1.x < p2.x ? 1 : -1;
    int sy = p1.y < p2.y ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        image_draw_pixel(screen, image, p1, color);
        if (p1.x == p2.x && p1.y == p2.y)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; p1.x += sx; }
        if (e2 < dx) { err += dx; p1.y += sy; }
    }    
}