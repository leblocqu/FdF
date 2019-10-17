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

void    show_points(void *mlxptr, void *winptr, t_fdf fdf)
{
    int x;
    int y;
    int previous_a;
    int previous_b;
    int new_a;
    int new_b;
    float t;
    float u;

    x = 0;
    y = 0;
    previous_a = 300;
    previous_b = 300;
    t = cos(30);
    u = sin(30);
    while (x < fdf.nb_lines)
    {
        while (y < fdf.nb_cols)
        {
            if (fdf.map[x][y] == 0)
            {
                new_a = (previous_a * t) - (previous_b * u);
                new_b = -((previous_b * t) + (previous_a * u)); 
                printf("new_a = %d\n", new_a);
                printf("new_b = %d\n", new_b);
                mlx_pixel_put(mlxptr, winptr, new_a, new_b, 0xFFFFFF);
            }
            else
            {
                new_a = (previous_a * t) - (previous_b * u);
                new_b = -((previous_b * t) + (previous_a * u)); 
                mlx_pixel_put(mlxptr, winptr, new_a, new_b, 0x850606);
            }
            
            y++;
            previous_a += 20;
        }
        previous_a = 300;
        previous_b += 20;
        y = 0;
        x++;
    }
}

// t_fdf   new_points(t_fdf fdf)
// {
//     int i;
//     int j;
//     int previous_x;
//     int previous_y;

//     i = 0;
//     j = 0;
//     previous_x = i;
//     previous_y = j;
//     while (i < fdf.nb_lines)
//     {
//         while (j < fdf.nb_cols)
//         {   
//             previous_x = j;

//             j++;
//         }
//         j = 0;
//         i++;
//     }
// }

int     main(int argc, char **argv)
{
    char    buff[BUFF_SIZE + 1];
    char    *str;
    int     fd;
    int     ret;
    t_fdf   fdf;
    void    *mlxptr;
    void    *winptr;

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
    mlxptr = mlx_init();
    winptr = mlx_new_window(mlxptr, 2000, 1000, "entrainement");
    show_points(mlxptr, winptr, fdf);
    mlx_loop(mlxptr);
    return (0);
}
