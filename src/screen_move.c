#include "fdf.h"

void    screen_move_up(t_screen *screen)
{
    screen->y -= 10;
}

void    screen_move_down(t_screen *screen)
{
    screen->y += 10;
}

void    screen_move_left(t_screen *screen)
{
    screen->x -= 10;
}

void    screen_move_right(t_screen *screen)
{
    screen->x += 10;
}