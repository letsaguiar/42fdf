#include "fdf.h"

static void screen_clean(t_screen *screen)
{
    t_image *image = screen->image;
    for (int y = 0; y < screen->screen_height; y++)
        for (int x = 0; x < screen->screen_width; x++)
            image_draw_pixel(image, (t_point){x, y, 0} ,0x000000);
}

static void calc_top_left(t_point *point, t_screen *screen, int x, int y, size_t offset_x, size_t offset_y)
{
    int dstX = x * screen->tile_width;
    int dstY = y * screen->tile_height;
    int dstZ = screen->map->data[y][x];

    *point = (t_point){
        dstX - offset_x + screen->move_right - screen->move_left,
        dstY - offset_y + screen->move_down - screen->move_up,
        dstZ
    };

    project(screen, point, offset_x, offset_y);
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

static void calc_bottom_right(t_point *point, t_screen *screen, int x, int y, size_t offset_x, size_t offset_y)
{
    if ((size_t)x + 1 >= screen->map->width || (size_t)y + 1 >= screen->map->height)
        return (calc_top_left(point, screen, x, y, offset_x, offset_y));
    
    return (calc_top_left(point, screen, x + 1, y + 1, offset_x, offset_y));
}

void    screen_render(t_screen *screen)
{
    t_map *map = screen->map;

    size_t map_height = map->height * screen->tile_height;
    size_t screen_height = screen->screen_height;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = map->width * screen->tile_width;
    size_t screen_width = screen->screen_width;
    size_t offset_x = (screen_width - map_width) / 2;

    screen_clean(screen);

    for (size_t y = 0; y < map->height; y++)
        for (size_t x = 0; x < map->width; x++)
        {
            t_point top_left, top_right, bottom_left, bottom_right;
            calc_top_left(&top_left, screen, x, y, offset_x, offset_y);
            calc_top_right(&top_right, screen, x, y, offset_x, offset_y);
            calc_bottom_left(&bottom_left, screen, x, y, offset_x, offset_y);
            calc_bottom_right(&bottom_right, screen, x, y, offset_x, offset_y);

            image_draw_line(screen->image, top_left, top_right, 0x00FF00);
            image_draw_line(screen->image, top_left, bottom_left, 0x00FF00);
            image_draw_line(screen->image, top_right, bottom_right, 0x00FF00);
            image_draw_line(screen->image, bottom_left, bottom_right, 0x00FF00);
        }
}