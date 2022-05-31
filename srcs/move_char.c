/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:26 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/01 00:30:17 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(int keycode, t_data *vars)
{
	if (keycode == EXIT)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}


int	check_key(int key, t_data *vars)
{
	if (key == A && vars->map.map[vars->p_i][vars->p_j - 1] != '1')
	{
		vars->p_j--;
		image_set(vars);
	}
	else if (key == W && vars->map.map[vars->p_i - 1][vars->p_j] != '1')
	{	
		vars->p_i--;
		image_set(vars);
	}
	else if (key == S && vars->map.map[vars->p_i + 1][vars->p_j] != '1')
	{	
		vars->p_i++;
		image_set(vars);
	}
	else if (key == D && vars->map.map[vars->p_i][vars->p_j + 1] != '1')
	{	
		vars->p_j++;
		image_set(vars);
	}
						
	return (0);
}