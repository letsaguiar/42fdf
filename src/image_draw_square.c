#include "fdf.h"
#include <math.h>

void    image_draw_square(t_image *image, t_point point, int offset_x, int offset_y, int color)
{
    int tile_offset = TILE_SIZE / 2;
    t_point p1 = {point.x - tile_offset, point.y - tile_offset, point.z};
    t_point p2 = {point.x + tile_offset, point.y - tile_offset, point.z};
    t_point p3 = {point.x + tile_offset, point.y + tile_offset, point.z};
    t_point p4 = {point.x - tile_offset, point.y + tile_offset, point.z};

    project(&p1, offset_x, offset_y); project(&p2, offset_x, offset_y);
    project(&p3, offset_x, offset_y); project(&p4, offset_x, offset_y);

    image_draw_line(image, p1, p2, color);
    image_draw_line(image, p2, p3, color);
    image_draw_line(image, p3, p4, color);
    image_draw_line(image, p4, p1, color);
}