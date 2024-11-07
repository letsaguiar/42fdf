#include "fdf.h"

void    map_clear(t_map *map)
{
    if (map->data)
    {
        for (size_t i = 0; i < map->height; i++)
            free(map->data[i]);
        free(map->data);
    }
    free(map);
}