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

typedef struct s_point
{
    int x;
    int y;
}              t_point;

typedef struct s_fdf
{
    int     **map;
    int     nb_lines;
    int     nb_cols;
    int     space;
    void    *mlxptr;
    void    *winptr;
    int     win_length;
    int     win_width;
    t_point point;
}              t_fdf;

void    draw_all(t_fdf *fdf);
void    init_fdf(t_fdf *fdf, char *str);
void    create_map(char *str, t_fdf *fdf);
void    full_up_map(char *str, t_fdf *fdf);
void    get_cols_lines(char *str, t_fdf *fdf);
void    drawline(t_fdf *fdf, t_point p0, t_point p1);
void    drawline_vertical(t_fdf *fdf, t_point p0, t_point p1);
void	size_window(t_fdf *fdf);
void	ft_space(t_fdf *fdf);
int     ft_mlx(t_fdf *fdf);

#endif