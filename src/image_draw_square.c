#include "fdf.h"

// Integer approximations of isometric constants
#define SQRT2_OVER_2 707
#define SQRT6_OVER_3 816
#define SQRT3_OVER_3 577
#define SCALE_FACTOR 1000

static void point_build(t_point *point, int x, int y, int z)
{
    point->x = ((SQRT2_OVER_2 * (x - y)) / SCALE_FACTOR) + (SCREEN_SIZE / 2);
    point->y = ((SQRT6_OVER_3 * (x + y) - (SQRT3_OVER_3 * z)) / SCALE_FACTOR) + (SCREEN_SIZE / 2);
}

void image_draw_square(t_image *image, t_point point, int color)
{
    int block_size = 25;

    t_point p1, p2, p3, p4;
    point_build(&p1, point.x, point.y, point.z);
    point_build(&p2, point.x + block_size, point.y, point.z);
    point_build(&p3, point.x + block_size, point.y + block_size, point.z);
    point_build(&p4, point.x, point.y + block_size, point.z);

    image_draw_line(image, p1, p2, color);
    image_draw_line(image, p2, p3, color);
    image_draw_line(image, p3, p4, color);
    image_draw_line(image, p4, p1, color);
}
