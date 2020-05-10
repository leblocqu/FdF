/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leblocqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:36:33 by leblocqu          #+#    #+#             */
/*   Updated: 2019/10/15 15:36:34 by leblocqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    get_max(t_fdf *fdf)
{
    int i;
    int j;
    int max;

    max = 0;
    i = 0;
    j = 0;
    if (fdf->map.nb_cols == 0)
    {
        fdf->map.max = 0;
        return ;
    }
    while (i < fdf->map.nb_lines)
    {
        while (j < fdf->map.nb_cols)
        {
            if (fdf->map.map[i][j] > max)
                fdf->map.max = fdf->map.map[i][j];
            j++;
        }
        j = 0;
        i++;
    }
}

void    create_map(char *str, t_fdf *fdf)
{
    int i;
    int j;

    i = 0;
    j = 0;
    get_cols_lines(str, fdf);
    fdf->map.map = ft_memalloc(sizeof(int **) * (fdf->map.nb_lines));
    while (i < fdf->map.nb_lines)
    {
        fdf->map.map[i] = ft_memalloc(sizeof(int *) * fdf->map.nb_cols);
        while (str[j] != '\n' && str[j] != '\0')
            j++;
        j++;
        i++;
    }
    full_up_map(str, fdf);
}

void    full_up_map(char *str, t_fdf *fdf)
{
    int i;
    int x;
    int y;
    int test;

    i = -1;
    x = 0;
    y = 0;
    test = 0;
    while (str[++i] != '\0')
    {
        while (str[i] != '\n')
        {
            if (ft_isdigit(str[i]) || str[i] == '-')
            {
                fdf->map.map[x][y] = ft_atoi(&str[i]);
                while (ft_isdigit(str[i + 1]))
                    i++;
                y++;
                test++;
            }
            i++;
        }
        x++;
        y = 0;
    }
}

void    get_cols_lines(char *str, t_fdf *fdf)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            fdf->map.nb_lines++;
        i++;
    }
    i = 0;
    while(str[i] != '\n' || str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 1)
        {
            fdf->map.nb_cols++;
            while (ft_isdigit(str[i]) == 1)
                i++;
            if (str[i] == '\n'  || str[i] == '\0' || str[i + 1] == '\n' || str[i] == '\0')
                return ;
        }
        i++;
    }
}