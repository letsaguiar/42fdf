#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void    map_iter_row(t_map *map, void (*f)(void *, int, int, int), void *params)
{
    for (size_t y = 0; y < map->height; y++)
    {
        for (size_t x = 0; x < map->width; x++)
        {
            f(params, x, y, map->data[y][x]);
        }
    }
}

void    map_iter_col(t_map *map, void (*f)(void *, int, int, int), void *params)
{
    for (size_t x = 0; x < map->width; x++)
    {
        for (size_t y = 0; y < map->height; y++)
        {
            f(params, x, y, map->data[y][x]);
        }
    }
}