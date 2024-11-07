#include "fdf.h"

void    screen_render_iter(void *params, int x, int y, int z)
{
    t_screen *screen = params;
    t_map *map = screen->map;
    t_image *image = screen->image;

    size_t map_height = map->height * TILE_SIZE;
    size_t screen_height = SCREEN_SIZE;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = map->width * TILE_SIZE;
    size_t screen_width = SCREEN_SIZE;
    size_t offset_x = (screen_width - map_width) / 5 * 4;

    t_point point = {x * TILE_SIZE, y * TILE_SIZE, z};
    image_draw_square(image, point, offset_x, offset_y, 0x00FF00);
}

void    screen_render(t_screen *screen)
{
    map_iter_row(screen->map, screen_render_iter, screen);
}