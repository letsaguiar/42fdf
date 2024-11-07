#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static void row_clear(char **row)
{
    for (size_t i = 0; row[i]; i++)
        free(row[i]);
    free(row);
}

void    map_iter(t_map *map, void (*f)(void *, int, int, int), void *params)
{
    int fd = open(map->filename, O_RDONLY);
    if (fd < 0)
        return ;

    t_string line = NULL;
    int y = 0;
    while ((line = get_next_line(fd)))
    {
        t_string *split = ft_split(line, ' ');
        for (int x = 0; split[x]; x++)
            f(params, x, y, ft_atoi(split[x]));

        free(line);
        row_clear(split);

        y++;
    }

    close(fd);
}