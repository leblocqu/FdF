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

void	draw_col(t_fdf *fdf)
{
	
}

void    draw_cols(t_fdf *fdf)
{
    fdf->map.x = 0;
    fdf->point.x = 0;
    while (fdf->point.x < fdf->map.nb_cols * fdf->point.space)
    {
        fdf->map.x = 0;
        fdf->point.y = 0;
        ft_get_p1_cols(t_fdf *fdf);
        ft_draw_col(t_fdf *fdf);

    }
}

void    draw_lines()
{

}

void    draw_all(t_fdf *fdf)
{

    draw_cols(fdf);
    draw_lines();
}

// fdf->point.x1 = fdf->point.x + (fdf->point.cte * (fdf->map.pad * Z1PC));
// 		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) *
// 				(fdf->map.pad * Z1PC));

// void    draw_all(t_fdf *fdf)
// {
//     int i;
//     int j;
//     int x;
//     int y;
//     int f;
//     int new_x;
//     int new_y;

//     i = 0;
//     j = 0;
//     x = 250;
//     y = 250;
//     f = 64;
//     while (fdf->map.nb_lines > i)
//     {
//         while (fdf->map.nb_cols > j)
//         {
//             new_x = x + (0.5 * (1 * fdf->map.map[i][j]));
// 	            new_y = y + ((0.5 / 2) * (-1 * fdf->map.map[i][j]));
//             printf("new_x = %d\n", new_x);
//             printf("new_y = %d\n", new_y);
//             mlx_pixel_put(fdf->mlxptr, fdf->winptr, new_x, new_y, 0xd6b017);
//             x += 20;
//             j++;
//         }
//         x = 250;
//         y += 20;
//         j = 0;
//         i++;
//     }
// }

// void    draw_all(t_fdf *fdf)
// {
//     int i;
//     int j;
//     int x;
//     int y;
//     t_point p0;
//     t_point p1;
//     int testx;
//     int testy;
//     int f;
    
//     x = 250;
//     y = 250;
//     i = 1;
//     j = 0;
//     f = 64;
//     testx = 250 + (fdf->map.nb_cols * fdf->space);
//     testy = 250 + (fdf->map.nb_lines * fdf->space);
//     while (fdf->map.nb_lines >= i)
//     {
//         while (fdf->map.nb_cols > j)
//         {
//             p0.x = x;
//             p0.y = y;
//             p1.x = x + fdf->space;
//             p1.y = y;
//             if (p1.x < testx)
//                 drawline(fdf, p0, p1);
//             p0.x = x;
//             p0.y = y;
//             p1.x = x;
//             p1.y = y + fdf->space;
//             if (p1.y < testy)
//                 drawline(fdf, p0, p1);
//             j++;
//             x += fdf->space;
//         }
//         y += fdf->space;
//         x = 250;
//         i++;
//         j = 0;
//     }
// }

// // t_fdf   rotation(t_fdf fdf)
// // {
// //     int x;
// //     int y;

// //     x = 0;
// //     y = 0;
// //     while (y < fdf->nb_lines)
// //     {
// //         while (x < fdf->nb_cols)
// //         {
            
// //         }
// //     }
// // }

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