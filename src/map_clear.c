#include "fdf.h"

void    map_clear(t_map map)
{
    size_t  i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}