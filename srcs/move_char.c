/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:26 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/02 18:45:24 by mgranate         ###   ########.fr       */
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
	if (vars->map.clt == 0 && vars->map.map[vars->p_i][vars->p_j] == 'E')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	consumable(t_data *vars, int key)
{
	if (vars->map.map[vars->p_i][vars->p_j - 1] == 'C' && key == A)
	{	
		vars->map.map[vars->p_i][vars->p_j - 1] = '0';
		vars->map.clt--;
	}	
	else if (vars->map.map[vars->p_i - 1][vars->p_j] == 'C' && key == W)
	{
		vars->map.map[vars->p_i - 1][vars->p_j] = '0';
		vars->map.clt--;
	}
	else if (vars->map.map[vars->p_i + 1][vars->p_j] == 'C' && key == S)
	{
		vars->map.map[vars->p_i + 1][vars->p_j] = '0';
		vars->map.clt--;
	}
	else if (vars->map.map[vars->p_i][vars->p_j + 1] == 'C' && key == D)
	{
		vars->map.map[vars->p_i][vars->p_j + 1] = '0';
		vars->map.clt--;
	}
}

int	check_key(int key, t_data *vars)
{
	if (key == A && vars->map.map[vars->p_i][vars->p_j - 1] != '1')
	{
		consumable(vars, key);
		vars->p_j--;
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerL, 64 * vars->p_j, 64 * vars->p_i);
		vars->stp++;
	}
	else if (key == W && vars->map.map[vars->p_i - 1][vars->p_j] != '1')
	{
		consumable(vars, key);	
		vars->p_i--;
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerB, 64 * vars->p_j, 64 * vars->p_i);
		vars->stp++;
	}
	else if (key == S && vars->map.map[vars->p_i + 1][vars->p_j] != '1')
	{	
		consumable(vars, key);
		vars->p_i++;
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 64 * vars->p_j, 64 * vars->p_i);
		vars->stp++;
	}
	else if (key == D && vars->map.map[vars->p_i][vars->p_j + 1] != '1')
	{	
		consumable(vars, key);
		vars->p_j++;
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerR, 64 * vars->p_j, 64 * vars->p_i);
		vars->stp++;
	}					
	ft_printf("%d\n", vars->stp);
	return (0);
}