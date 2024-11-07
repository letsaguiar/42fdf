#include "fdf.h"

void    screen_render(t_screen *screen)
{
    t_point point = {400, 400, 0};
    image_draw_pixel(screen->image, point, 0x00FF00);
}