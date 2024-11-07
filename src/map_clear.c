#include "fdf.h"

void    map_clear(t_map *map)
{
    if (map->filename)
        free(map->filename);
    free(map);
}