#include "fdf.h"

static int screen_key_press(int keycode, t_screen *screen)
{
    if (keycode == XK_Escape)
    {
        screen_clear(screen);
        exit(0);
    }

    return (0);
}

static int screen_destroy(t_screen *screen)
{
    screen_clear(screen);
    exit(0);
    return (0);
}

void    screen_run(t_screen *screen)
{
    mlx_hook(screen->win, DestroyNotify, StructureNotifyMask, screen_destroy, screen);
    mlx_hook(screen->win, KeyPress, KeyPressMask, screen_key_press, screen);
    mlx_loop(screen->mlx);
}