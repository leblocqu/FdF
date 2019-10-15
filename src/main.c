/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:29 by leblocqu          #+#    #+#             */
/*   Updated: 2019/10/09 15:30:31 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    show_points(/*void *mlxptr, void *winptr, */t_fdf fdf)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < fdf.nb_lines)
    {
        while (y < fdf.nb_cols)
        {
            printf("%d", fdf.map[x][y]);
            y++;
        }
        printf("\n");
        y = 0;
        x++;
    }
}

int     main(int argc, char **argv)
{
    char    buff[BUFF_SIZE + 1];
    char    *str;
    int     fd;
    int     ret;
    t_fdf   fdf;
    // void    *mlxptr;
    // void    *winptr;

    ret = 0;
    buff[0] = '\0';
    str = NULL;
    fdf.map = NULL;
    fdf.nb_lines = 0;
    fdf.nb_cols = 0;
    if (argc != 2)
    {
        printf("error entree\n");
        return (0);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str = ft_strjoin(str, buff)))
			return (0);
	}
    fdf = init_fdf(fdf, str);
    // mlxptr = mlx_init();
    // winptr = mlx_new_window(mlxptr, 1000, 1000, "entrainement");
    // mlx_loop(mlxptr);
    return (0);
}
