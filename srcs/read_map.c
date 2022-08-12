/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:44:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/08/12 15:04:56 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**create_map(int fd, char **map, int height)
{
	char	*str;

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

static int	check_map_dimensions(t_data *vars)
{
	int	i;

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

static int	check_end_begin(t_data *vars)
{
	int	i;
	int	j;

	vars->win_height = vars->win_height - 1;
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

int	map_making(char *map, t_data *vars)
{
	int	fd;

	vars->map.clt = 0;
	vars->map.exit = 0;
	vars->map.p = 0;
	vars->win_height = 0;
	fd = open(map, O_RDONLY);
	vars->map.map = create_map (fd, NULL, vars->win_height);
	if (!check_map_dimensions(vars))
		return (0);
	if (!check_end_begin(vars))
		return (0);
	if (!check_map_middle(vars))
		return (0);
	if (!check_elements(vars))
		return (0);
	return (1);
}
