/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/11 18:32:46 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int check_map_middle(char *line, int width, t_data *vars)
{
    width = width - 1;
    if (line[width] != '1' || line[0] != '1')
    {
        ft_printf("Error\n");
        ft_printf("MAP Has Missing Walls\n");
        return (0); 
    }
    while (width > -1)
    {
        if (line[width] != '1' && line[width] != '0' && line[width] != 'C' 
        && line[width] != 'E' && line[width] != 'P' &&line[width] != 'N')
        {
            ft_printf("Error\n");
            ft_printf("Wrong MAP Configuration\n");
            return (0);
        }
        if (line[width] == 'C')
            vars->map.clt++;
        width--;
    }
    return (1);
}

static int check_begin_line(char *line, t_data *vars)
{
    int width;

    width = vars->win_width - 1;
    while ((width) > -1)
    {
        if  (line[width] != '1')
        {
            ft_printf("Error\n");
            ft_printf("MAP Has Missing Walls\n");
            return (0);
        }
        width--;
    }
    return (1);
}

static int check_end_line(char *map, t_data *vars)
{
    int     fd;
    int     i;

	vars->map.map = (char **)malloc((vars->win_height + 1) * sizeof(char *));
    i = 0;
    fd = open(map, O_RDONLY);
    while ((vars->map.map[i] = get_next_line(fd)))
        i++;
    if (!check_begin_line(vars->map.map[i - 1] , vars))
        return (0);
    return (1);
}

static int check_dimensions(char *line, t_data *vars, int fd)
{
    int cp;
    
    while ((line = get_next_line(fd)))
    {
        cp =  ft_strlen_get(line);
        vars->win_height++;
        if (cp != vars->win_width)
        {
            ft_printf("Error\n");
            ft_printf("Incorrect Map Dimensions\n");
            return (0);
        }
        if(!check_map_middle(line, vars->win_width, vars))
            return (0);
    }
    free(line);
    return (1);
}

int map_width(char *map, t_data	*vars)
{
    char    *str;
    int     fd;

    vars->win_height = 1;
    fd = open(map, O_RDONLY);
    str = get_next_line(fd);
    vars->win_width = ft_strlen_get(str);
    if (!check_dimensions(str, vars, fd))
        return (0);
    if (!check_begin_line(str, vars))
        return (0);
    if (!check_end_line(map, vars))
        return (0);
    return (1);
}
