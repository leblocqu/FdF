/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:52 by leblocqu          #+#    #+#             */
/*   Updated: 2019/10/09 15:30:54 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 1

typedef struct s_fdf
{
    int **map;
    int nb_lines;
    int nb_cols;
}              t_fdf;

t_fdf   init_fdf(t_fdf fdf, char *str);
int     **create_map(char *str, t_fdf fdf);
int     **full_up_map(char *str, int **map);
t_fdf   get_cols_lines(char *str, t_fdf fdf);
void    show_points(void *mlxptr, void *winptr, t_fdf fdf);

#endif