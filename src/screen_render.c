#include "fdf.h"
#include "math.h"
#include <stdio.h>

static void screen_render_points(void *params, int x, int y, int z)
{
    static int block_size = 25;

    int dstX = (x * block_size) + (cos(120) * z);
    int dstY = (y * block_size) + (sin(120) * z);

    t_screen *screen = params;
    image_draw_pixel(screen->image, dstX, dstY, 0x00FFFFFF);
}

void    screen_render(t_screen *screen)
{
    map_iter_col(screen->map, screen_render_points, screen);
}