/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:31:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/08/12 17:57:10 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_mlx(vars);
	exit (0);
}

int	key_a_check(t_data *vars)
{
	if (vars->map.map[vars->p_i][vars->p_j] == 'N' && vars->e != 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood,
			64 * (vars->p_j + 1), 64 * vars->p_i);
		return (0);
	}
	if (vars->map.map[vars->p_i][vars->p_j - 1] != '1'
			&& vars->e == 0 && vars->map.map[vars->p_i][vars->p_j - 1] != 'E')
		return (2);
	return (1);
}

int	key_w_check(t_data *vars)
{
	if (vars->map.map[vars->p_i][vars->p_j] == 'N' && vars->e != 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood,
			64 * vars->p_j, 64 * (vars->p_i + 1));
		return (0);
	}
	if (vars->map.map[vars->p_i - 1][vars->p_j] != '1'
			&& vars->e == 0 && vars->map.map[vars->p_i - 1][vars->p_j] != 'E')
		return (2);
	return (1);
}

int	key_s_check(t_data *vars)
{
	if (vars->map.map[vars->p_i][vars->p_j] == 'N' && vars->e != 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood,
			64 * vars->p_j, 64 * (vars->p_i - 1));
		return (0);
	}
	if (vars->map.map[vars->p_i + 1][vars->p_j] != '1'
			&& vars->e == 0 && vars->map.map[vars->p_i + 1][vars->p_j] != 'E')
		return (2);
	return (1);
}

int	key_d_check(t_data *vars)
{
	if (vars->map.map[vars->p_i][vars->p_j] == 'N' && vars->e != 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood,
			64 * (vars->p_j - 1), 64 * vars->p_i);
		return (0);
	}
	if (vars->map.map[vars->p_i][vars->p_j + 1] != '1'
			&& vars->e == 0 && vars->map.map[vars->p_i][vars->p_j + 1] != 'E')
		return (2);
	return (1);
}
