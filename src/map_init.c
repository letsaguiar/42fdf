#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static void row_clear(char **row)
{
    for (size_t i = 0; row[i]; i++)
        free(row[i]);
    free(row);
}

static size_t   get_width(t_string filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);

    char *line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (0);
    }

    char **split = ft_split(line, ' ');
    if (!split)
    {
        close(fd);
        free(line);
        return (0);
    }

    size_t width = 0;
    while (split[width])
        width++;

    close(fd);
    free(line);
    row_clear(split);
    return (width);
}

static size_t   get_height(t_string filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);

    t_string line;
    size_t height = 0;
    while ((line = get_next_line(fd)))
    {
        free(line);
        height++;
    }

    close(fd);
    return (height);
}

t_map   *map_init(t_string filename)
{
    if (!map_validate(filename))
    {
        ft_printf("Invalid map file\n");
        return (NULL);
    }

    t_map *map = ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = get_width(filename);
    map->height = get_height(filename);
    map->data = ft_calloc(map->height, sizeof(int *));
    if (!map->data)
    {
        free(map);
        return (NULL);
    }

    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    t_string line = NULL;
    for (size_t i = 0; (line = get_next_line(fd)); i++)
    {
        map->data[i] = ft_calloc(map->width, sizeof(int));
        if (!map->data[i])
        {
            map_clear(map);
            close(fd);
            return (NULL);
        }

        char **split = ft_split(line, ' ');
        if (!split)
        {
            map_clear(map);
            close(fd);
            free(line);
            return (NULL);
        }

        for (size_t j = 0; split[j]; j++)
            map->data[i][j] = ft_atoi(split[j]);

        row_clear(split);
        free(line);
    }

    return (map);
}