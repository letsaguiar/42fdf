#include "fdf.h"

static void calc_top_left(t_point *point, t_screen *screen, int x, int y, size_t offset_x, size_t offset_y)
{
    int dstX = x * TILE_SIZE;
    int dstY = y * TILE_SIZE;
    int dstZ = screen->map->data[y][x];

    *point = (t_point){dstX - offset_x, dstY - offset_y, dstZ};
    project(point, offset_x, offset_y);
}

static void calc_top_right(t_point *point, t_screen *screen, int x, int y, size_t offset_x, size_t offset_y)
{
    if ((size_t)x + 1 >= screen->map->width)
        return (calc_top_left(point, screen, x, y, offset_x, offset_y));
    
    return (calc_top_left(point, screen, x + 1, y, offset_x, offset_y));
}

static void calc_bottom_left(t_point *point, t_screen *screen, int x, int y, size_t offset_x, size_t offset_y)
{
    if ((size_t)y + 1 >= screen->map->height)
        return (calc_top_left(point, screen, x, y, offset_x, offset_y));
    
    return (calc_top_left(point, screen, x, y + 1, offset_x, offset_y));
}

void    screen_render(t_screen *screen)
{
    t_map *map = screen->map;

    size_t map_height = map->height * TILE_SIZE;
    size_t screen_height = SCREEN_SIZE;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = map->width * TILE_SIZE;
    size_t screen_width = SCREEN_SIZE;
    size_t offset_x = (screen_width - map_width) / 2;

    for (size_t y = 0; y < map->height; y++)
        for (size_t x = 0; x < map->width; x++)
        {
            t_point top_left, top_right, bottom_left;
            calc_top_left(&top_left, screen, x, y, offset_x, offset_y);
            calc_top_right(&top_right, screen, x, y, offset_x, offset_y);
            calc_bottom_left(&bottom_left, screen, x, y, offset_x, offset_y);

            image_draw_line(screen->image, top_left, top_right, 0x00FF00);
            image_draw_line(screen->image, top_left, bottom_left, 0x00FF00);
        }
}