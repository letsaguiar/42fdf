#include "fdf.h"

void    screen_zoom_in(t_screen *screen)
{
    screen->tile_width += 2;
    screen->tile_height += 2;
}

void    screen_zoom_out(t_screen *screen)
{
    screen->tile_width -= 2;
    screen->tile_height -= 2;
}