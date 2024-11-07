#include "fdf.h"

t_map   *map_init(t_string filename)
{
    t_map *map = ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);

    map->filename = ft_strdup(filename);
    map->width = 0;
    map->height = 0;
    return (map_validate(map));
}