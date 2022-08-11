/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/16 17:44:26 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **create_map (int fd, char **map, int height)
{
    char    *str;

    str = get_next_line(fd);
    if (str)
        map = create_map(fd, map, 1 + height);
    if (!map && height)
        map = malloc((height + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    map[height] = str;
    return (map);
}

int check_map_dimensions(t_data *vars)
{
    int i;

    i = 0;
    vars->win_width = ft_strlen(vars->map.map[0]);
    while (vars->map.map[i])
    {
        if (vars->win_width != (int)ft_strlen(vars->map.map[i]))
        {
            ft_printf("Error\n");
            ft_printf("Incorrect Map Dimensions\n");
            return (0);
        }
        i++;
        vars->win_height ++;
    }
    return (1);
}

int check_end_begin(t_data *vars)
{
    int i;
    int j;

    vars->win_height  = vars->win_height - 1;
    i = vars->win_height;
    while (i >= 0)
    {
        j = 0;
        while (vars->map.map[i][j])
        {
            if (vars->map.map[i][j] != '1')
            {
                ft_printf("Error\n");
                ft_printf("Missing Walls!\n");
                return (0);
            }
            j++;
        }
        i = i - vars->win_height;
    }
    return (1);
}

static int check_map_middle(t_data *vars)
{
    int i;
    int j;

    vars->win_width = vars->win_width - 1;
    vars->map.clt = 0;
    i = -1;
    while (vars->map.map[++i])
    {
        j = 0;
        if (vars->map.map[i][vars->win_width] != '1' || vars->map.map[i][0] != '1')
        {
            ft_printf("----DEBUGG----\n");
            ft_printf("Error\n");
            ft_printf("MAP Has Missing Walls\n");
        }
        while (vars->map.map[i][j])
        {
            if (vars->map.map[i][j] != '1' && vars->map.map[i][j] != '0' && vars->map.map[i][j] != 'C' 
            && vars->map.map[i][j] != 'E' && vars->map.map[i][j] != 'P' &&vars->map.map[i][j] != 'N')
            {
                ft_printf("----DEBUGG2----\n");
                ft_printf("Error\n");
                ft_printf("Wrong MAP Configuration\n");
                return (0);
            }
            if (vars->map.map[i][j] == 'C')
                vars->map.clt++;
            j++;
        }
    }
    return (1);
}

int map_making(char *map, t_data *vars)
{
    int     fd;

    vars->win_height = 0;
    fd = open(map, O_RDONLY);
    vars->map.map = create_map (fd, NULL, vars->win_height);
    if(!check_map_dimensions(vars))
        return(0);
    if(!check_end_begin(vars))
        return (0);
    if (!check_map_middle(vars))
        return (0);
    return (1);
}
