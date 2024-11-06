#include "fdf.h"

t_screen    *screen_init()
{
    t_screen *screen = ft_calloc(1, sizeof(t_screen));
    if (!screen)
        return (NULL);

    screen->mlx = mlx_init();
    if (!screen->mlx)
    {
        screen_clear(screen);
        return (NULL);
    }

    screen->win = mlx_new_window(screen->mlx, SCREEN_SIZE, SCREEN_SIZE, "FDF");
    if (!screen->win)
    {
        screen_clear(screen);
        return (NULL);
    }

    return (screen);
}