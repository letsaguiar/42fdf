#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

static void row_clear(char **row)
{
    for (size_t i = 0; row[i]; i++)
        free(row[i]);
    free(row);
}

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
        t_string *row = ft_split(line, ' ');

        size_t tmp = 0;
        for (size_t i = 0; row[i]; i++)
            tmp++;
        if (width == 0)
            width = tmp;
        else if (tmp != width)
        {
            row_clear(row);
            free(line);
            close(fd);
            return (FALSE);
        }

        row_clear(row);
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