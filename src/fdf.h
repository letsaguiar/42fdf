#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 800
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 800
# endif

# ifndef TILE_WIDTH
#  define TILE_WIDTH 25
# endif

# ifndef TILE_HEIGHT
#  define TILE_HEIGHT 30 
# endif

typedef struct s_map
{
    int     **data;
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
    int         tile_width;
    int         tile_height;
    int         screen_width;
    int         screen_height;
} t_screen;

typedef struct s_point
{
    int x;
    int y;
    int z;
} t_point;

t_map       *map_init(t_string filename);

t_bool      map_validate(t_string filename);

void        map_iter_row(t_map *map, void (*f)(void *, int, int, int), void *params);

void        map_iter_col(t_map *map, void (*f)(void *, int, int, int), void *params);

void        map_clear(t_map *map);

t_screen    *screen_init(t_map *map);

void        screen_run(t_screen *screen);

void        screen_render(t_screen *screen);

void        screen_clear(t_screen *screen);

t_image     *image_init(t_screen *screen);

void        image_draw_pixel(t_image *image, t_point point, int color);

void        image_draw_line(t_image *image, t_point p1, t_point p2, int color);

void        image_clear(t_screen *screen, t_image *image);

void        project(t_point *point, int offset_x, int offset_y);

#endif