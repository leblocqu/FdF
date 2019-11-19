/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:53:59 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/12 14:54:02 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_fdf *fdf, int x, int y)
{
	if (x > 0 && y > 0 && x < fdf->win_length && y < fdf->win_width)
	{
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line)] = fdf->color.red;
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line) + 1] = fdf->color.green;
		fdf->data[(x * (fdf->bpp / 8)) +
			(y * fdf->size_line) + 2] = fdf->color.blue;
	}
}

void	ft_key_hook_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->map.l_r += 40;
	if (keycode == KEY_LEFT)
		fdf->map.l_r -= 40;
	if (keycode == KEY_DOWN)
		fdf->map.d_u += 40;
	if (keycode == KEY_UP)
		fdf->map.d_u -= 40;
}

void	ft_key_hook_alt(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PAD_ADD)
	{
		fdf->point.cte += 0.3;
		fdf->point.pos += 5;
	}
	else if (keycode == KEY_PAD_SUB)
	{
		fdf->point.cte -= 0.3;
		fdf->point.pos -= 5;
	}
}

void	ft_key_hook_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PAD_1)
	{
		fdf->point.space -= 5;
		if (fdf->point.space <= 0)
			fdf->point.space += 5;
	}
	else if (keycode == KEY_PAD_2)
		fdf->point.space += 5;
}

void	ft_key_hook_proj(t_fdf *fdf)
{
	if (fdf->proj == 0)
		fdf->proj = 1;
	else if (fdf->proj == 1)
		fdf->proj = 0;
}

void	ft_key_hook_color(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_R)
		fdf->color.red -= 20;
	if (keycode == KEY_G)
		fdf->color.green -= 20;
	if (keycode == KEY_B)
		fdf->color.blue -= 20;
}