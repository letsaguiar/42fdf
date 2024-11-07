#include "fdf.h"
#include "math.h"

void    image_draw_line(t_image *image, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);    
    int step = dx > dy ? dx : dy;

    int x = x0;
    int y = y0;

    for (int i = 0; i <= step; i++)
    {
        image_draw_pixel(image, x, y, color);
        x += dx / step;
        y += dy / step;
    }
}