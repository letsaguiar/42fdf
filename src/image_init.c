#include "fdf.h"

t_image     *image_init(t_screen *screen)
{
    t_image *image = ft_calloc(1, sizeof(t_image));
    if (!image)
        return (NULL);

    image->img = mlx_new_image(screen->mlx, SCREEN_SIZE, SCREEN_SIZE);
    if (!image->img)
    {
        free(image);
        return (NULL);
    }

    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    if (!image->addr)
    {
        free(image);
        return (NULL);
    }

    return (image);
}