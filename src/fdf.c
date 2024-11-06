#include "fdf.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    t_string filename = argv[1];
    if (!map_validate(filename))
    {
        ft_printf("Invalid map\n");
        return (1);
    }

    return (0);
}