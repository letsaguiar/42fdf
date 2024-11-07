#include "fdf.h"
#include "math.h"

void    image_draw_line(t_image *image, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++)
    {
        image_draw_pixel(image, round(x), round(y), color);
        x += x_inc;
        y += y_inc;
    }
}