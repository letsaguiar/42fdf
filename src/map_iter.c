#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void    map_iter(t_string filename, void (*f)(int, int, int))
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return ;

    t_string line = NULL;
    size_t y = 0;
    while ((line = get_next_line(fd)))
    {
        t_string* row = ft_split(line, ' ');
        if (!row)
        {
            close(fd);
            return ;
        }

        for (size_t x = 0; row[x]; x++)
            f(x, y, ft_atoi(row[x]));

        map_clear(row);
        free(line);
        y++;
    }
}