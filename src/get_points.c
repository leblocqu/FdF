/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:04:13 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/07 16:04:15 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_bresenham(t_fdf *fdf)
{
	fdf->point.dx = (abs(fdf->point.x2 - fdf->point.x1));
	fdf->point.sx = (fdf->point.x1 < fdf->point.x2 ? 1 : -1);
	fdf->point.dy = (abs(fdf->point.y2 - fdf->point.y1));
	fdf->point.sy = (fdf->point.y1 < fdf->point.y2 ? 1 : -1);
	fdf->point.err = (fdf->point.dx > fdf->point.dy ?
			fdf->point.dx : -fdf->point.dy) / 2;
		// printf("trucx = %d && trucy = %d\n", fdf->map.l_r + fdf->point.x1, fdf->map.d_u + fdf->point.y1);
	while (1)
	{
		//printf("trucquix = %d\n && trucquiy = %d\n", fdf->map.l_r, fdf->map.d_u);
		ft_pixel_put(fdf, fdf->map.l_r + fdf->point.x1,
					fdf->map.d_u + fdf->point.y1);
		if (fdf->point.x1 == fdf->point.x2 && fdf->point.y1 == fdf->point.y2)
			break ;
		fdf->point.e2 = fdf->point.err;
		if (fdf->point.e2 > -fdf->point.dx)
		{
			fdf->point.err -= fdf->point.dy;
			fdf->point.x1 += fdf->point.sx;
		}
		if (fdf->point.e2 < fdf->point.dy)
		{
			fdf->point.err += fdf->point.dx;
			fdf->point.y1 += fdf->point.sy;
		}
	}
}

void    get_p1_cols(t_fdf *fdf)
{
    if (fdf->proj == 0)
	{
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x])));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x])));
	}
	else
	{
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			fdf->point.y;
		fdf->point.y1 = ((fdf->point.pos * (fdf->map.map[fdf->map.y][fdf->map.x])) + (fdf->point.cte1 / 2) *
				fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y);
	}
	// printf("poin.x1 = %d && point.y1 = %d\n", fdf->point.x1, fdf->point.y1);
}

void	get_p2_cols(t_fdf *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x2 = fdf->point.x + (fdf->point.cte * (fdf->map.max * (fdf->map.map[fdf->map.y + 1][fdf->map.x])));
		fdf->point.y2 = (fdf->point.y + fdf->point.space) +
			((fdf->point.cte / 2) * (fdf->map.max * (fdf->map.map[fdf->map.y + 1][fdf->map.x])));
	}
	else
	{
		fdf->point.x2 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			(fdf->point.y + fdf->point.space);
		fdf->point.y2 = (fdf->point.pos * (fdf->map.map[fdf->map.y + 1][fdf->map.x])) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) *
			(fdf->point.y + fdf->point.space);
	}
	// printf("poin.x2 = %d && point.y2 = %d\n", fdf->point.x2, fdf->point.y2);
}

void	get_p1_line(t_fdf *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x1 = fdf->point.x + (fdf->point.cte * (fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x])));
		fdf->point.y1 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x])));
	}
	else
	{
		fdf->point.x1 = fdf->point.cte1 * fdf->point.x - fdf->point.cte2 *
			fdf->point.y;
		fdf->point.y1 = (fdf->point.pos * (fdf->map.map[fdf->map.y][fdf->map.x])) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) * fdf->point.y;
	}
}

void	get_p2_line(t_fdf *fdf)
{
	if (fdf->proj == 0)
	{
		fdf->point.x2 = (fdf->point.x + fdf->point.space) + (fdf->point.cte *
				(fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x + 1])));
		fdf->point.y2 = fdf->point.y + ((fdf->point.cte / 2) *
				(fdf->map.max * (fdf->map.map[fdf->map.y][fdf->map.x + 1])));
	}
	else
	{
		fdf->point.x2 = fdf->point.cte1 * (fdf->point.x + fdf->point.space) -
			fdf->point.cte2 * fdf->point.y;
		fdf->point.y2 = (fdf->point.pos * (fdf->map.map[fdf->map.y][fdf->map.x + 1])) + (fdf->point.cte1 / 2) *
			fdf->point.x + (fdf->point.cte2 / 2) *
			(fdf->point.y + fdf->point.space);
	}
}