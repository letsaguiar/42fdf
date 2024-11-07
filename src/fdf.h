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

typedef char** t_map;

typedef struct s_image
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_image;


typedef struct s_screen
{
    void    *mlx;
    void    *win;
    t_image *image;
} t_screen;

t_bool      map_validate(t_string filename);

void        map_iter(t_string filename, void (*f)(int, int, int));

void        map_clear(t_map map);

t_screen    *screen_init();

void        screen_run(t_screen *screen);

void        screen_clear(t_screen *screen);

t_image     *image_init(t_screen *screen);

void        image_clear(t_screen *screen, t_image *image);

#endif