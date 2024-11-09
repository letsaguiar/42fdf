#include "fdf.h"

void    screen_move_up(t_screen *screen)
{
    screen->move_up += 10;
}

void    screen_move_down(t_screen *screen)
{
    screen->move_down += 10;
}

void    screen_move_left(t_screen *screen)
{
    screen->move_left += 10;
}

void    screen_move_right(t_screen *screen)
{
    screen->move_right += 10;
}