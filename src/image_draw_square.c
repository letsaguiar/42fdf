#include "fdf.h"
#include <math.h>
#include <stdio.h>

void    project(t_point *point, int offset_x, int offset_y)
{
    float angle = 30 * M_PI / 180; 

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