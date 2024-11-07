#include "fdf.h"

void    screen_render_iter(void *params, int x, int y, int z)
{
    size_t map_height = TILE_SIZE * 2;
    size_t screen_height = SCREEN_SIZE;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = TILE_SIZE * 2;
    size_t screen_width = SCREEN_SIZE;
    size_t offset_x = (screen_width - map_width) / 2;

    t_point point = {x * TILE_SIZE, y * TILE_SIZE, z};
    image_draw_square((t_image *)params, point, offset_x, offset_y, 0x00FF00);
}

void    screen_render(t_screen *screen)
{
    map_iter_row(screen->map, screen_render_iter, screen->image);
}