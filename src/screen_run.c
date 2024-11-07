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

static int screen_loop(t_screen *screen)
{
    for (size_t i = 0; i < SCREEN_SIZE; i++)
    {
        for (size_t j = 0; j < SCREEN_SIZE; j++)
        {
            image_draw_pixel(screen->image, i, j, 0xFFFFFF);
        }
    }

    mlx_put_image_to_window(screen->mlx, screen->win, screen->image->img, 0, 0);

    return (0);
}

void    screen_run(t_screen *screen)
{
    mlx_hook(screen->win, DestroyNotify, StructureNotifyMask, screen_destroy, screen);
    mlx_hook(screen->win, KeyPress, KeyPressMask, screen_key_press, screen);
    mlx_loop_hook(screen->mlx, screen_loop, screen);
    mlx_loop(screen->mlx);
}