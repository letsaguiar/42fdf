#include "fdf.h"

static void screen_render_iter(void *params, int x, int y)
{
    t_screen *screen = params;
    image_draw_pixel(screen->image, x, y, 0x00FFFFFF);
}

void    screen_render(t_screen *screen)
{
    map_iter(screen->filename, screen_render_iter, screen);
}