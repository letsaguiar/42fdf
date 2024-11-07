#include "fdf.h"

void    screen_render(t_screen *screen)
{
    t_point p1 = {0, 0, 0};
    t_point p2 = {800, 400, 0};
    image_draw_line(screen->image, p1, p2, 0x00FF00);
}