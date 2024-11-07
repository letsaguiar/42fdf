#include "fdf.h"

void    screen_render(t_screen *screen)
{
    t_point p2 = {400, 400, 0};
    image_draw_square(screen->image, p2, 0x00FF00);
}