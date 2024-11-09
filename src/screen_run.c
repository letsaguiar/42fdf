#include "fdf.h"

static int screen_button_press(int button, int x, int y, t_screen *screen)
{
    (void)x;
    (void)y;
    
    if (button == 1)
        screen->left_mouse_down = TRUE;
    else if (button == 3)
        screen->right_mouse_down = TRUE;
    else if (button == 4)
        screen_zoom_in(screen);
    else if (button == 5)
        screen_zoom_out(screen);
    return (0);
}

static int screen_button_release(int button, int x, int y, t_screen *screen)
{
    (void)x;
    (void)y;
    
    if (button == 1)
        screen->left_mouse_down = FALSE;
    if (button == 3)
        screen->right_mouse_down = FALSE;
    return (0);
}

static int screen_mouse_move(int x, int y, t_screen *screen)
{
    if (screen->left_mouse_down)
    {
        int dx = x - screen->mouse_x;
        int dy = y - screen->mouse_y;
        float sensitivity = 0.9;

        screen->x += dx * sensitivity;
        screen->y += dy * sensitivity;
    }
    if (screen->right_mouse_down)
    {
        int dy = y - screen->mouse_y;
        float sensitivity = 0.01;

        screen->y_angle += dy * sensitivity;
    }

    screen->mouse_x = x;
    screen->mouse_y = y;
    return (0);
}

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

void    screen_run(t_screen *screen)
{
    mlx_hook(screen->win, DestroyNotify, StructureNotifyMask, screen_destroy, screen);
    mlx_hook(screen->win, KeyPress, KeyPressMask, screen_key_press, screen);
    mlx_hook(screen->win, ButtonPress, ButtonPressMask, screen_button_press, screen);
    mlx_hook(screen->win, ButtonRelease, ButtonReleaseMask, screen_button_release, screen);
    mlx_hook(screen->win, MotionNotify, PointerMotionMask, screen_mouse_move, screen);
    mlx_loop_hook(screen->mlx, screen_loop, screen);
    mlx_loop(screen->mlx);
}