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

char    *init(char *argv)
{
    char    buff[BUFF_SIZE + 1];
    char    *str;
    int     fd;
    int     ret;

    ret = 0;
    buff[0] = '\0';
    str = NULL;
    if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
    if (!(fd))
        return (NULL);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str = ft_strjoin_free(str, buff, 1)))
			return (0);
	}
    return (str);
}

int     main(int argc, char **argv)
{
    t_fdf   fdf;

    if (argc != 2)
    {
        printf("Error Syntax Entree\n");
        return (0);
    }
    ft_bzero(&fdf, sizeof(t_fdf));
    init_fdf(fdf, init(argv[1]));
    free(&fdf);
    return (0);
}
