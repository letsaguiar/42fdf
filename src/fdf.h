#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# ifndef SCREEN_SIZE
#  define SCREEN_SIZE 800
# endif

typedef struct s_map
{
    char    *filename;
    size_t  width;
    size_t  height;
} t_map;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_image;


typedef struct s_screen
{
    void        *mlx;
    void        *win;
    t_map       *map;
    t_image     *image;
} t_screen;

t_map       *map_init(t_string filename);

t_map       *map_validate(t_map *map);

void        map_iter(t_map *map, void (*f)(void *, int, int, int), void *params);

void        map_clear(t_map *map);

t_screen    *screen_init(t_map *map);

void        screen_run(t_screen *screen);

void        screen_render(t_screen *screen);

void        screen_clear(t_screen *screen);

t_image     *image_init(t_screen *screen);

void        image_draw_pixel(t_image *image, int x, int y, int color);

void        image_clear(t_screen *screen, t_image *image);

#endif