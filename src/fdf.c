#include "ft_printf.h"
#include <mlx.h>

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 500, 500, "fdf");
    if (!win)
        return (1);

    mlx_loop(mlx);
}