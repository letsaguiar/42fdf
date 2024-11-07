#include "fdf.h"

void    screen_render(t_screen *screen)
{
    size_t map_height = TILE_SIZE * 2;
    size_t screen_height = SCREEN_SIZE;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = TILE_SIZE * 2;
    size_t screen_width = SCREEN_SIZE;
    size_t offset_x = (screen_width - map_width) / 2;

    t_point p1 = {0, 0, 0};
    t_point p2 = {0, 20, 0};
    t_point p3 = {20, 0, 0};
    image_draw_square(screen->image, p1, offset_x, offset_y, 0x00FF00);
    image_draw_square(screen->image, p2, offset_x, offset_y, 0x00FF00);
    image_draw_square(screen->image, p3, offset_x, offset_y, 0x00FF00);
}