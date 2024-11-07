#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static void row_clear(char **row)
{
    for (size_t i = 0; row[i]; i++)
        free(row[i]);
    free(row);
}

static t_bool   map_validate_empty(t_map *map)
{
    int fd = open(map->filename, O_RDONLY);
    if (fd < 0)
        return (FALSE);

    char buffer = '\0';
    read(fd, &buffer, 1);
    close(fd);

    return (buffer != '\0');
}

static t_bool   map_validate_width(t_map *map)
{
    int fd = open(map->filename, O_RDONLY);
    if (fd < -1)
        return (FALSE);

    t_string line = NULL;
    size_t height = 0;
    while ((line = get_next_line(fd)))
    {
        t_string *row = ft_split(line, ' ');

        size_t tmp = 0;
        for (size_t i = 0; row[i]; i++)
            tmp++;
        if (map->width == 0)
            map->width = tmp;
        else if (tmp != map->width)
        {
            map_clear(map);
            row_clear(row);
            free(line);
            close(fd);
            return (FALSE);
        }

        row_clear(row);
        free(line);
        height++;
    }
    map->height = height;

    close(fd);
    return (TRUE);
}

t_map   *map_validate(t_map *map)
{
    if (
        !map_validate_empty(map)
        || !map_validate_width(map)
    )
        return (NULL);

    return (map);
}