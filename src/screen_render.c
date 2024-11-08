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

void    screen_render_connect(void *params, int x, int y, int z)
{
    t_screen *screen = params;
    t_map *map = screen->map;
    int **data = map->data;
    t_image *image = screen->image;

    size_t map_height = map->height * TILE_SIZE;
    size_t screen_height = SCREEN_SIZE;
    size_t offset_y = (screen_height - map_height) / 2;

    size_t map_width = map->width * TILE_SIZE;
    size_t screen_width = SCREEN_SIZE;
    size_t offset_x = (screen_width - map_width) / 5 * 4;

    if ((size_t)x < map->width - 1)
    {
        t_point point = {x * TILE_SIZE, y * TILE_SIZE, z};
        t_point right = { (x + 1) * TILE_SIZE, y * TILE_SIZE, data[y][x + 1] };

        int tile_offset = TILE_SIZE / 2;
        t_point p1 = {point.x + tile_offset, point.y - tile_offset, point.z};
        t_point p2 = {point.x + tile_offset, point.y + tile_offset, point.z};
        t_point p3 = {right.x - tile_offset, right.y - tile_offset, right.z};
        t_point p4 = {right.x - tile_offset, right.y + tile_offset, right.z};

        project(&p1, offset_x, offset_y); project(&p2, offset_x, offset_y);
        project(&p3, offset_x, offset_y); project(&p4, offset_x, offset_y);

        if (point.z != right.z)
        {
            image_draw_line(image, p1, p3, 0x00FF00);
            image_draw_line(image, p2, p4, 0x00FF00);
        }
    }

    if ((size_t)y < map->height - 1)
    {
        t_point point = {x * TILE_SIZE, y * TILE_SIZE, z};
        t_point down = { x * TILE_SIZE, (y + 1) * TILE_SIZE, data[y + 1][x] };

        int tile_offset = TILE_SIZE / 2;
        t_point p1 = {point.x - tile_offset, point.y + tile_offset, point.z};
        t_point p2 = {point.x + tile_offset, point.y + tile_offset, point.z};
        t_point p3 = {down.x - tile_offset, down.y - tile_offset, down.z};
        t_point p4 = {down.x + tile_offset, down.y - tile_offset, down.z};

        project(&p1, offset_x, offset_y); project(&p2, offset_x, offset_y);
        project(&p3, offset_x, offset_y); project(&p4, offset_x, offset_y);

        if (point.z != down.z)
        {
            image_draw_line(image, p1, p3, 0x00FF00);
            image_draw_line(image, p2, p4, 0x00FF00);
        }
    }
}

void    screen_render(t_screen *screen)
{
    map_iter_row(screen->map, screen_render_iter, screen);
    map_iter_row(screen->map, screen_render_connect, screen);
}