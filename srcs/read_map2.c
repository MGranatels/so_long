/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:04:28 by mgranate          #+#    #+#             */
/*   Updated: 2022/08/12 17:47:03 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_resources(char cord, t_data *vars)
{
	if (cord == 'C')
		vars->map.clt++;
	if (cord == 'E')
		vars->map.exit++;
	if (cord == 'P')
		vars->map.p++;
}

static int	check_map_middle2(char gps, t_data *vars)
{
	if (gps != '1' && gps != '0'
		&& gps != 'C'
		&& gps != 'E' && gps != 'P'
		&& gps != 'N')
	{
		ft_printf("Error\n");
		ft_printf("Wrong MAP Configuration\n");
		return (0);
	}
	check_resources(gps, vars);
	return (1);
}

int	check_map_middle(t_data *vars)
{
	int	i;
	int	j;

	vars->win_width = vars->win_width - 1;
	i = -1;
	while (vars->map.map[++i])
	{
		j = 0;
		if (vars->map.map[i][vars->win_width] != '1' ||
			vars->map.map[i][0] != '1')
		{
			ft_printf("Error\n");
			ft_printf("MAP Has Missing Walls\n");
			return (0);
		}
		while (vars->map.map[i][j])
		{
			if (!check_map_middle2(vars->map.map[i][j], vars))
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_elements(t_data *vars)
{
	if (vars->map.clt == 0)
	{
		ft_printf("Wrong Map Configuration:\n");
		ft_printf("Map does not have any collectables!\n");
		return (0);
	}
	if (vars->map.exit == 0)
	{
		ft_printf("Wrong Map Configuration:\n");
		ft_printf("Map does not have an Exit!\n");
		return (0);
	}
	if (vars->map.p == 0)
	{
		ft_printf("Wrong Map Configuration:\n");
		ft_printf("Map does not have any player!\n");
		return (0);
	}
	return (1);
}
