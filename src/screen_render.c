#include "fdf.h"
#include "math.h"

static void screen_render_iter(void *params, int x, int y, int z)
{
    int dstX = x + cos(120) * z;
    int dstY = y + sin(120) * z;

    t_screen *screen = params;
    image_draw_pixel(screen->image, dstX, dstY, 0x00FFFFFF);
}

void    screen_render(t_screen *screen)
{
    map_iter(screen->filename, screen_render_iter, screen);
}