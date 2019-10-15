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

int     **create_map(char *str, t_fdf fdf)
{
    int i;
    int j;
    int **map;

    i = 0;
    j = 0;
    map = ft_memalloc(sizeof(int **) * (fdf.nb_lines));
    while (i < fdf.nb_lines)
    {
        map[i] = ft_memalloc(sizeof(int *) * fdf.nb_cols);
        while (str[j] != '\n' && str[j] != '\0')
            j++;
        j++;
        i++;
    }
    return (map);
}

int     **full_up_map(char *str, int **map)
{
    int i;
    int x;
    int y;

    i = -1;
    x = 0;
    y = 0;

    while (str[++i] != '\0')
    {
        while (str[i] != '\n')
        {
            if (ft_isdigit(str[i]))
            {
                map[x][y] = ft_getnbr(&str[i]);
                while (ft_isdigit(str[i + 1]))
                    i++;
                y++;
            }
            i++;
        }
        x++;
        y = 0;
    }
    return (map);
}

t_fdf     get_cols_lines(char *str, t_fdf fdf)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            fdf.nb_lines++;
        i++;
    }
    fdf.nb_lines++;
    i = 0;
    while(str[i] != '\n' || str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            fdf.nb_cols++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            if (str[i] == '\n' || str[i] == '\0')
                return (fdf);
        }
        i++;
    }
    return (fdf);
}