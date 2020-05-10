/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:52 by leblocqu          #+#    #+#             */
/*   Updated: 2020/05/06 17:37:58 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include "key_code.h"

# define BUFF_SIZE 1

typedef struct s_point
{
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;
    double          space;
    double			cte;
	double			cte1;
	double			cte2;
	int				pos;
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;
}              t_point;

typedef struct s_map
{
    int **map;
    int x;
    int y;
    int nb_lines;
    int nb_cols;
    int max;
    int	l_r;
	int d_u;
}               t_map;

typedef struct s_color
{
    int color;
    int red;
    int green;
    int blue;
}               t_color;

typedef struct s_fdf
{
    void    *mlxptr;
    void    *winptr;
    int     win_length;
    int     win_width;
    void	*img_ptr;
	char	*data;
    int     bpp;
    int     size_line;
    int     endian;
    int     proj;
    t_map   map;
    t_point point;
    t_color color;
}              t_fdf;

void    init_fdf(t_fdf fdf, char *str);
void    create_map(char *str, t_fdf *fdf);
void    full_up_map(char *str, t_fdf *fdf);
void    get_cols_lines(char *str, t_fdf *fdf);
void	size_window(t_fdf *fdf);
void	ft_space(t_fdf *fdf);
int     ft_mlx(t_fdf *fdf);
void    get_p1_cols(t_fdf *fdf);
void	get_p2_cols(t_fdf *fdf);
void	get_p1_line(t_fdf *fdf);
void	get_p2_line(t_fdf *fdf);
void	draw_col(t_fdf *fdf);
void	draw_cols(t_fdf *fdf);
void	draw_line(t_fdf *fdf);
void	draw_lines(t_fdf *fdf);
void    draw_all(t_fdf *fdf);
int     key_hook(int keycode, t_fdf *fdf);
int     expose_hook(t_fdf *fdf);
void    get_max(t_fdf *fdf);
void	ft_bresenham(t_fdf *fdf);
void	ft_pixel_put(t_fdf *fdf, int x, int y);
void	ft_key_hook_move(int keycode, t_fdf *fdf);
void	ft_key_hook_alt(int keycode, t_fdf *fdf);
void	ft_key_hook_zoom(int keycode, t_fdf *fdf);
void	ft_key_hook_proj(t_fdf *fdf);
void	ft_init(t_fdf *fdf);
int     expose_hook(t_fdf *fdf);
void	ft_key_hook_color(int keycode, t_fdf *fdf);
void    draw_menu(t_fdf *fdf);
void    draw_cube(t_fdf *fdf);
void    draw_cube_2(t_fdf *fdf);
void    draw_cube_3(t_fdf *fdf);

#endif
