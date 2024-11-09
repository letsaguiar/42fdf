#include "fdf.h"
#include <math.h>

t_screen    *screen_init(t_map *map)
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

    screen->win = mlx_new_window(screen->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
    if (!screen->win)
    {
        screen_clear(screen);
        return (NULL);
    }

    screen->image = image_init(screen);
    if (!screen->image)
    {
        screen_clear(screen);
        return (NULL);
    }

    screen->map = map;
    screen->tile_width = TILE_WIDTH;
    screen->tile_height = TILE_HEIGHT;
    screen->width = SCREEN_WIDTH;
    screen->height = SCREEN_HEIGHT;
    screen->x = 0;
    screen->y = 0;
    screen->angle = M_PI / 6.0f;
    screen->left_mouse_down = FALSE;
    screen->right_mouse_down = FALSE;

    return (screen);
}