#include "fdf.h"

void    image_clear(t_screen *screen, t_image *image)
{
    if (image->img)
        mlx_destroy_image(screen->mlx, image->img);
    free(image);
}