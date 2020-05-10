/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:26 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/19 14:53:27 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_menu(t_fdf *fdf)
{
    int y;

    y = 0;
    draw_cube(fdf);
    draw_cube_2(fdf);
    draw_cube_3(fdf);
    mlx_string_put(fdf->mlxptr, fdf->winptr, 75, y += 20, RED, " --- H.E.L.P --- ");
	mlx_string_put(fdf->mlxptr, fdf->winptr, 25, y += 30, WHITE, "Zoom : Z/S Key");
	mlx_string_put(fdf->mlxptr, fdf->winptr, 25, y += 30, WHITE, "Move : Arrows");
	mlx_string_put(fdf->mlxptr, fdf->winptr, 25, y += 30, WHITE, "Projection : P Key");
	mlx_string_put(fdf->mlxptr, fdf->winptr, 25, y += 30, WHITE, "Flatten : Numpad +/-");
	mlx_string_put(fdf->mlxptr, fdf->winptr, 25, y += 50, WHITE, "Quit program : ESC");
}

void    draw_cube(t_fdf *fdf)
{
    int x;
    int y;
    int y2;
    int x2;

    x = 15;
    y = 28;
    y2 = 205;
    x2 = 240;
    while (x < 240)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y2, RED);
        x++;
    }
    x = 15;
    while (y < 205)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x2, y, RED);
        y++;
    }
}

void    draw_cube_2(t_fdf *fdf)
{
    int x;
    int y;
    int y2;
    int x2;

    x = 14;
    y = 27;
    y2 = 206;
    x2 = 241;
    while (x < 241)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y2, RED);
        x++;
    }
    x = 14;
    while (y < 206)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x2, y, RED);
        y++;
    }
}

void    draw_cube_3(t_fdf *fdf)
{
    int x;
    int y;
    int y2;
    int x2;

    x = 13;
    y = 26;
    y2 = 207;
    x2 = 242;
    while (x < 242)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y2, RED);
        x++;
    }
    x = 13;
    while (y < 207)
    {
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, RED);
        mlx_pixel_put(fdf->mlxptr, fdf->winptr, x2, y, RED);
        y++;
    }
}