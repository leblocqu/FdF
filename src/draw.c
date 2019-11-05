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

void    draw_all(t_fdf *fdf)
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
    testx = 250 + (fdf->nb_cols * fdf->space);
    testy = 250 + (fdf->nb_lines * fdf->space);
    while (fdf->nb_lines >= i)
    {
        while (fdf->nb_cols > j)
        {
            p0.x = x;
            p0.y = y;
            p1.x = x + fdf->space;
            p1.y = y;
            if (p1.x < testx)
                drawline(fdf, p0, p1);
            p0.x = x;
            p0.y = y;
            p1.x = x;
            p1.y = y + fdf->space;
            if (p1.y < testy)
                drawline(fdf, p0, p1);
            j++;
            x += fdf->space;
        }
        y += fdf->space;
        x = 250;
        i++;
        j = 0;
    }
}

// t_fdf   rotation(t_fdf fdf)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while (y < fdf->nb_lines)
//     {
//         while (x < fdf->nb_cols)
//         {
            
//         }
//     }
// }

void    drawline(t_fdf *fdf, t_point p0, t_point p1)
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
        drawline_vertical(fdf, p0, p1);
        return ;
    }
	while (x < p1.x)
	{
		if (p >= 0)
		{
            mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, 0xd6b017);
			y = y + 1;
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
            mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, 0xd6b017);
			p = p + 2 * d.y;
		}
		x = x + 1;
	}
}

void    drawline_vertical(t_fdf *fdf, t_point p0, t_point p1)
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
            mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, 0xd6b017);
			p = p + 2 * d.y - 2 * d.x;
		}
		else
		{
            mlx_pixel_put(fdf->mlxptr, fdf->winptr, x, y, 0xd6b017);
			p = p + 2 * d.y;
		}
		y = y + 1;
	}
}