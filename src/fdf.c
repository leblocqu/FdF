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

t_fdf   init_fdf(t_fdf fdf, char *str)
{
    fdf = get_cols_lines(str, fdf);
    fdf.map = create_map(str, fdf);
    fdf.map = full_up_map(str, fdf.map);
    return (fdf);
}
