#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <mlx.h>

typedef char** t_map;

t_bool  map_validate(t_string filename);

void    map_clear(t_map map);

#endif