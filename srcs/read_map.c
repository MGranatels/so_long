/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/05/29 18:38:39 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int check_map_middle(char *line, int width)
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
        && line[width] != 'E' && line[width] != 'P')
        {
            ft_printf("Error\n");
            ft_printf("Wrong MAP Configuration\n");
            return (0);
        }
        width--;
    }
    return (1);
}

static int check_begin_line(char *line, int width)
{
    while ((width - 1) > -1)
    {
        if  (line[width - 1] != '1')
        {
            ft_printf("Error\n");
            ft_printf("MAP Has Missing Walls\n");
            return (0);
        }
        width--;
    }
    return (1);
}

static int check_end_line(char *map, int height, int width)
{
    int     fd;
    char    *line;
    
    fd = open(map, O_RDONLY);
    while (height > 0)
    {
        line = get_next_line(fd);
        height--;
    }
    if (!check_begin_line(line, width))
        return (0);
    return (1);
}

static int check_dimensions(char *line, int width, t_data *vars, int fd)
{
    int cp;
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        cp =  ft_strlen(line) - 1;
        vars->win_height++;
        if (cp != width)
        {
            ft_printf("Error\n");
            ft_printf("Incorrect Map Dimensions\n");
            return (0);
        }
        if(!check_map_middle(line, width))
            return (0);
    }
    return (1);
}

int map_width(char *map, t_data	*vars)
{
    char    *str;
    int     fd;

    vars->win_height = 1;
    fd = open(map, O_RDONLY);
    str = get_next_line(fd);
    vars->win_width = ft_strlen(str) - 1;
    if (!check_dimensions(str, vars->win_width, vars, fd))
        return (0);
    if (!check_begin_line(str, vars->win_width))
        return (0);
    if (!check_end_line(map, vars->win_height, vars->win_width))
        return (0);
    return (1);
}
