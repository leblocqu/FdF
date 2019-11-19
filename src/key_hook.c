/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:08:06 by leblocqu          #+#    #+#             */
/*   Updated: 2019/11/05 17:08:07 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_R || keycode == KEY_B || keycode == KEY_G)
		ft_key_hook_color(keycode, fdf);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT
			|| keycode == KEY_DOWN ||
			keycode == KEY_UP)
		ft_key_hook_move(keycode, fdf);
	else if (keycode == KEY_PAD_ADD || keycode == KEY_PAD_SUB)
		ft_key_hook_alt(keycode, fdf);
	else if (keycode == KEY_PAD_1 || keycode == KEY_PAD_2)
		ft_key_hook_zoom(keycode, fdf);
	else if (keycode == KEY_P)
		ft_key_hook_proj(fdf);
	else if (keycode == KEY_Z)
		ft_init(fdf);
	expose_hook(fdf);
	return (0);
}

int	expose_hook(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlxptr, fdf->win_length, fdf->win_width);
	fdf->data = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	draw_all(fdf);
	mlx_put_image_to_window(fdf->mlxptr, fdf->winptr, fdf->img_ptr, 0, 0);
	draw_menu(fdf);
	mlx_destroy_image(fdf->mlxptr, fdf->img_ptr);
	return (0);
}