#include "fdf.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    t_string filename = argv[1];
    t_map *map = map_init(filename);
    if (!map)
    {
        ft_printf("Failed to initialize map\n");
        return (1);
    }

    t_screen *screen = screen_init(map);
    if (!screen)
    {
        ft_printf("Failed to initialize screen\n");
        return (1);
    }

    screen_run(screen);

    return (0);
}