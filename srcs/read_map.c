/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/05/28 19:07:57 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_next_line(int fd);

int map_width(char *map, t_data	vars)
{
    char    *str;
    int     fd;
    int     cp;

    fd = open(map, O_RDONLY);
    str = get_next_line(fd);
    vars.win_width = ft_strlen(str) - 1;
    ft_printf("map width = %d\n", vars.win_width);
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
        {
            free(str);
            break ;
        }
        ft_printf("line = %s \n", str);
        cp =  ft_strlen(str) - 1;
        ft_printf("cp width = %d\n", cp);
        if (cp != vars.win_width) 
            return (0);
    }
    return (vars.win_width);
    ft_printf("map width = %d\n", vars.win_width);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;

// 	i = 1;
// 	fd = open("read", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("Line %i: %s", i, str);
// 		if (!str)
// 			break ;
// 		free(str);
// 		i++;
// 	}
// }
