#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static t_bool   map_validate_empty(t_string filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (FALSE);

    char buffer = '\0';
    read(fd, &buffer, 1);
    close(fd);

    return (buffer != '\0');
}

static t_bool   map_validate_width(t_string filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < -1)
        return (FALSE);

    t_string line = NULL;
    size_t width = 0;
    while ((line = get_next_line(fd)))
    {
        t_map map = ft_split(line, ' ');

        size_t tmp = 0;
        for (size_t i = 0; map[i]; i++)
            tmp++;
        if (width == 0)
            width = tmp;
        else if (width != tmp)
        {
            map_clear(map);
            free(line);
            close(fd);
            return (FALSE);
        }

        map_clear(map);
        free(line);
    }

    close(fd);
    return (TRUE);
}

t_bool  map_validate(t_string filename)
{
    return (
        map_validate_empty(filename)
        && map_validate_width(filename)
    );
}