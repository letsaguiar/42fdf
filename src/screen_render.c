#include "fdf.h"

void    screen_render(t_screen *screen)
{
    image_draw_square(screen->image, (t_point){0, 0, 0}, 0x00FF00);
}