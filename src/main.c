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

int     get_x(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while(str[i] != '\n' || str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            res++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            if (str[i] == '\n' || str[i] == '\0')
                return (res);
        }
        i++;
    }
    return (res);
}

int     get_y(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            res++;
        i++;
    }
    return (res);
}

int     **create_map(char *str)
{
    int i;
    int j;
    int **map;

    i = 0;
    j = 0;
    map = ft_memalloc(sizeof(int **) * get_y(str));
    while (i < get_y(str))
    {
        map[i] = ft_memalloc(sizeof(int *) * get_x(&str[j]));
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

    i = 0;
    x = 0;
    y = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\n')
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                printf("str[i] = %c\n", str[i]);
                printf("get_nbr = %d\n", ft_getnbr(&str[i]));
                printf("x = %d\n", x);
                printf("y = %d\n", y);
                map[y][x] = ft_getnbr(&str[i]);
                x++;
                while (str[i] >= '0' && str[i] <= '9')
                {
                    printf("str[i] = %c\n", str[i]);
                    i++;
                }
            }
                printf("***\n");
        }
        x = 0;
        y++;
        i++;
    }
    return (map);
}

int     main(int argc, char **argv)
{
    char    buff[BUFF_SIZE + 1];
    char    *str;
    int     fd;
    int     ret;
    int     **map;

    ret = 0;
    buff[0] = '\0';
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
    map = create_map(str);
    map = full_up_map(str, map);
    return (0);
}
