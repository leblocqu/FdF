/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:33:54 by leblocqu          #+#    #+#             */
/*   Updated: 2019/10/15 15:34:13 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_fdf(t_fdf fdf, char *str)
{
    create_map(str, &fdf);
    get_max(&fdf);
    ft_space(&fdf);
    ft_mlx(&fdf);
    free(*(fdf.map.map));
	ft_bzero(&fdf, sizeof(t_fdf));
}
