#include "fdf.h"

void    image_draw_pixel(t_screen *screen, t_image *image, t_point point, int color)
{
    if (point.x < 0 || point.y < 0 || point.x >= screen->width || point.y >= screen->height)
        return ;

    char *dst;

    dst = image->addr + (point.y * image->line_length + point.x * (image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}