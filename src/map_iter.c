#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void    map_iter(t_string filename, void (*f)(void *, int, int, int), void *params)
{
    int fd = open(filename, O_RDONLY);
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
        map_clear(split);

        y++;
    }

    close(fd);
}