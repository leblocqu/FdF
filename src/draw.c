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
	while (fdf->point.y < ((fdf->map.nb_lines - 1) * fdf->point.space))
	{
		get_p2_cols(fdf);
		ft_bresenham(fdf);
		fdf->map.y++;
		fdf->point.y += fdf->point.space;
		fdf->point.x1 = fdf->point.x2;
		fdf->point.y1 = fdf->point.y2;
	}
}

void	draw_cols(t_fdf *fdf)
{
	fdf->map.x = 0;
	fdf->point.x = 0;
	// printf("truc = %f\n", fdf->map.nb_cols * fdf->point.space);
	// printf("point.x = %d\n", fdf->point.x);
	// printf("point.y = %d\n", fdf->point.y);
	while (fdf->point.x < fdf->map.nb_cols * fdf->point.space)
	{
		// printf("map.x = %d\n", fdf->map.x++);
		// printf("point.x = %d\n", fdf->point.x);
		fdf->point.y = 0;
		fdf->map.y = 0;
		get_p1_cols(fdf);
		draw_col(fdf);
		fdf->map.x++;
		fdf->point.x += fdf->point.space;
	}
}

void	draw_line(t_fdf *fdf)
{
	while (fdf->point.x < (fdf->map.nb_cols - 1) * fdf->point.space)
	{
		get_p2_line(fdf);
		ft_bresenham(fdf);
		fdf->map.x++;
		fdf->point.x += fdf->point.space;
		fdf->point.x1 = fdf->point.x2;
		fdf->point.y1 = fdf->point.y2;
	}
}

void	draw_lines(t_fdf *fdf)
{
	fdf->map.y = 0;
	fdf->point.y = 0;
	// printf("truc = %f\n", fdf->map.nb_cols * fdf->point.space);
	// printf("point.x = %d\n", fdf->point.x);
	while (fdf->point.y < fdf->map.nb_lines * fdf->point.space)
	{
		fdf->map.x = 0;
		fdf->point.x = 0;
		get_p1_line(fdf);
		draw_line(fdf);
		fdf->map.y++;
		fdf->point.y += fdf->point.space;
	}
}


void    draw_all(t_fdf *fdf)
{
    draw_cols(fdf);
    draw_lines(fdf);
}