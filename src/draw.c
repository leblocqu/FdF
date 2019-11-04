/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:43:36 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/04 11:43:38 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    draw_all(t_fdf fdf, t_mlx mlx)
{
    int i;
    int j;
    int x;
    int y;
    t_point p0;
    t_point p1;
    int testx;
    int testy;
    
    x = 250;
    y = 250;
    i = 1;
    j = 0;
    testx = 250 + (fdf.nb_cols * 20);
    testy = 250 + (fdf.nb_lines * 20);
    while (fdf.nb_lines >= i)
    {
        while (fdf.nb_cols > j)
        {
            p0.x = x;
            p0.y = y;
            p1.x = x + 20;
            p1.y = y;
            if (p1.x < testx)
                drawline(mlx, p0, p1);
            p0.x = x;
            p0.y = y;
            p1.x = x;
            p1.y = y + 20;
            if (p1.y < testy)
                drawline(mlx, p0, p1);
            j++;
            x += 20;
        }
        y += 20;
        x = 250;
        i++;
        j = 0;
    }
}

void    drawline(t_mlx mlx, t_point p0, t_point p1)
{
    t_point d;
    int p;
    int x;
    int y;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
 	x = p0.x;
	y = p0.y;
 	p = 2 * d.y - d.x;
    if (p0.x == p1.x)
    {
        drawline_vertical(mlx, p0, p1);
        return ;
    }
	while (x < p1.x)
	{
		if (p >= 0)
		{
            mlx_pixel_put(mlx.mlxptr, mlx.winptr, x, y, 0xd6b017);
            // printf("x = %d\n", x);
            // printf("y = %d\n", y);
			y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
            mlx_pixel_put(mlx.mlxptr, mlx.winptr, x, y, 0xd6b017);
            // printf("x = %d\n", x);
            // printf("y = %d\n", y);
			p = p + 2 * d.y;
		}
		x = x + 1;
	}
}

void    drawline_vertical(t_mlx mlx, t_point p0, t_point p1)
{
    t_point d;
    int p;
    int x;
    int y;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
 	x = p0.x;
	y = p0.y;
 	p = 2 * d.y - d.x;
	while (y < p1.y)
	{
		if (p >= 0)
		{
            mlx_pixel_put(mlx.mlxptr, mlx.winptr, x, y, 0xd6b017);
            // printf("x = %d\n", x);
            // printf("y = %d\n", y);
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
            mlx_pixel_put(mlx.mlxptr, mlx.winptr, x, y, 0xd6b017);
            // printf("x = %d\n", x);
            // printf("y = %d\n", y);
			p = p + 2 * d.y;
		}
		y = y + 1;
	}
}