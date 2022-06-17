/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:26 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/16 18:02:05 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	vars->stp++;
	ft_printf("%d\n", vars->stp);
}

static int	enemy_check(t_data *vars, int key)
{
	int	ret;

	image_set(vars);
	if (key == A)
		ret = key_a_check(vars);
	if (key == W)
		ret = key_w_check(vars);
	if (key == D)
		ret = key_d_check(vars);
	if (key == S)
		ret = key_s_check(vars);
	return (ret);
}

void	set_variables(t_data *vars, int key)
{
	if (vars->e == 0)
		image_set(vars);
	if (key == A && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerl,
			64 * vars->p_j, 64 * vars->p_i);
	if (key == W && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerb,
			64 * vars->p_j, 64 * vars->p_i);
	if (key == S && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player,
			64 * vars->p_j, 64 * vars->p_i);
	if (key == D && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerr,
			64 * vars->p_j, 64 * vars->p_i);
	check_key_nub(vars);
}

int	check_key(int key, t_data *vars)
{
	if (key == A && key_a_check(vars) == 2)
	{
		consumable(vars, key);
		vars->p_j--;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == W && key_w_check(vars) == 2)
	{
		consumable(vars, key);
		vars->p_i--;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == S && key_s_check(vars) == 2)
	{	
		consumable(vars, key);
		vars->p_i++;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == D && key_d_check(vars) == 2)
	{	
		consumable(vars, key);
		vars->p_j++;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}	
	return (0);
}
