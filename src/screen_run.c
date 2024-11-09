#include "fdf.h"

static int screen_key_press(int keycode, t_screen *screen)
{
    if (keycode == XK_Escape)
    {
        screen_clear(screen);
        exit(0);
    }
    if (keycode == XK_Up || keycode == XK_w)
        screen_move_up(screen);
    if (keycode == XK_Down || keycode == XK_s)
        screen_move_down(screen);
    if (keycode == XK_Left || keycode == XK_a)
        screen_move_left(screen);
    if (keycode == XK_Right || keycode == XK_d)
        screen_move_right(screen);

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
    screen_render(screen);
    mlx_put_image_to_window(screen->mlx, screen->win, screen->image->img, 0, 0);
    return (0);
}

static int screen_mouse_scroll(int button, int x, int y, t_screen *screen)
{
    (void)x;
    (void)y;
    
    if (button == 4)
        screen_zoom_in(screen);
    if (button == 5)
        screen_zoom_out(screen);
    return (0);
}

void    screen_run(t_screen *screen)
{
    mlx_hook(screen->win, DestroyNotify, StructureNotifyMask, screen_destroy, screen);
    mlx_hook(screen->win, KeyPress, KeyPressMask, screen_key_press, screen);
    mlx_hook(screen->win, ButtonPress, ButtonPressMask, screen_mouse_scroll, screen);
    mlx_loop_hook(screen->mlx, screen_loop, screen);
    mlx_loop(screen->mlx);
}