#include "fdf.h"

void    screen_clear(t_screen *screen)
{
    if (screen->filename)
        free(screen->filename);
    if (screen->image)
        image_clear(screen, screen->image);
    if (screen->win)
        mlx_destroy_window(screen->mlx, screen->win);
    if (screen->mlx)
    {
        mlx_destroy_display(screen->mlx);
        free(screen->mlx);
    }
    free(screen);
}