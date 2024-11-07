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

static void screen_render_lines_left(void *params, int x, int y, int z)
{
    static int block_size = 25;
    static int srcX = 0;
    static int srcY = 0;

    if (x == 0 && y == 0)
    {
        srcX = (x * block_size) + (cos(120) * z);
        srcY = (y * block_size) + (sin(120) * z);
    }
    else
    {
        int dstX = (x * block_size) + (cos(120) * z);
        int dstY = (y * block_size) + (sin(120) * z);

        t_screen *screen = params;
        image_draw_line(screen->image, srcX, srcY, dstX, dstY, 0x00FFFFFF);

        srcX = dstX;
        srcY = dstY;
    }
}

static void screen_render_lines_top(void *params, int x, int y, int z)
{
    static int block_size = 25;
    static int srcX = 0;
    static int srcY = 0;

    if (x == 0 && y == 0)
    {
        srcX = (x * block_size) + (cos(120) * z);
        srcY = (y * block_size) + (sin(120) * z);
    }
    else
    {
        int dstX = (x * block_size) + (cos(120) * z);
        int dstY = (y * block_size) + (sin(120) * z);

        t_screen *screen = params;
        image_draw_pixel(screen->image, dstX, dstY, 0x00FFFFFF);
        image_draw_line(screen->image, 0, 0, SCREEN_SIZE - 1, 400 ,0x00FFFFFF);
        printf("dstX: %d, dstY: %d\n", srcX, srcY);

        srcX = dstX;
        srcY = dstY;
    }
}

void    screen_render(t_screen *screen)
{
    map_iter(screen->map, screen_render_points, screen);
    map_iter(screen->map, screen_render_lines_left, screen);
    map_iter(screen->map, screen_render_lines_top, screen);
}