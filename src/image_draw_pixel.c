#include "fdf.h"

void    image_draw_pixel(t_image *image, int x, int y, int color)
{
    char *dst;

    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}