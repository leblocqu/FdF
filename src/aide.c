#include “mlx.h”
#include <unistd.h>
#include <stdio.h>
// -lmlx -framework OpenGL -framework AppKit

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int        deal_key(int key, void *param)
{
    ft_putchar(‘X’);
    return (0);
}
int        main()
{
    int i;
    int y;
    void    *mlxptr;
    void    *winptr;
    y = 999;
    i = 0;
    mlxptr = mlx_init();
    winptr = mlx_new_window(mlxptr, 1000, 1000, “entrainement”);
    while (i != 1000)
    {
        mlx_pixel_put(mlxptr, winptr, 500, i, 0xd6b017);
        mlx_pixel_put(mlxptr, winptr, i, 500, 0xd6b017);
        mlx_pixel_put(mlxptr, winptr, i, i, 0xd6b017);
        mlx_pixel_put(mlxptr, winptr, y, i, 0xd6b017);
        mlx_string_put(mlxptr, winptr, 500, 480, 0xd6b017, “42”);
        y--;
        i++;
    }
    mlx_key_hook(winptr, deal_key, (void *)0);
    mlx_loop(mlxptr);
}