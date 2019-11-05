/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:36:55 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/05 13:36:56 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_mlx(t_fdf *fdf)
{
	fdf->mlxptr = mlx_init();
	size_window(fdf);
	fdf->winptr = mlx_new_window(fdf->mlxptr, fdf->win_width , fdf->win_length, "entrainement");
	// mlx_key_hook(fdf.winptr, ft_key_hook, fdf);
	draw_all(fdf);
	mlx_loop(fdf->mlxptr);
	return (0);
}

void	size_window(t_fdf *fdf)
{
	if (fdf->nb_cols <= 10)
		fdf->win_length = fdf->nb_cols * 100;
	else if (fdf->nb_cols <= 20)
		fdf->win_length = fdf->nb_cols * 70;
	else if (fdf->nb_cols >= 20 && fdf->nb_cols <= 50)
		fdf->win_length = fdf->nb_cols * 40;
	else if (fdf->nb_cols >= 50 && fdf->nb_cols <= 100)
		fdf->win_length = fdf->nb_cols * 20;
	else if (fdf->nb_cols >= 100 && fdf->nb_cols <= 200)
		fdf->win_length = fdf->nb_cols * 10;
	else
		fdf->win_length = fdf->nb_cols * 10;
	if (fdf->nb_lines <= 20)
		fdf->win_width = fdf->nb_lines * 100;
	else if (fdf->nb_lines >= 20 && fdf->nb_lines <= 50)
		fdf->win_width = fdf->nb_lines * 40;
	else if (fdf->nb_lines >= 50 && fdf->nb_lines <= 100)
		fdf->win_width = fdf->nb_lines * 20;
	else if (fdf->nb_lines >= 100 && fdf->nb_lines <= 200)
		fdf->win_width = fdf->nb_lines * 10;
	else
		fdf->win_width = fdf->nb_lines * 10;
}

void	ft_space(t_fdf *fdf)
{
	if (fdf->nb_cols <= 20)
		fdf->space = 25;
	else if (fdf->nb_cols >= 20 && fdf->nb_cols <= 50)
		fdf->space = 20;
	else if (fdf->nb_cols >= 50 && fdf->nb_cols <= 100)
		fdf->space = 15;
	else if (fdf->nb_cols >= 100 && fdf->nb_cols <= 200)
		fdf->space = 5;
	else
		fdf->space = 1;
}