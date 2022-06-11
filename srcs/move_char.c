/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:26 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/11 19:38:52 by mgranate         ###   ########.fr       */
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
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, (850), (500), "GAME COMPLETED");
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.win_b, 0, 0);
		mlx_key_hook(vars->win, ft_close, vars);
		mlx_loop(vars->mlx);
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

static int	enemy_check(t_data *vars, int key)
{
	if (vars->map.map[vars->p_i][vars->p_j] == 'N' && key == A)
	{
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood, 
		64 * (vars->p_j + 1), 64 * vars->p_i);
		return (0);
	}
	else if (vars->map.map[vars->p_i][vars->p_j] == 'N' && key == W)
	{
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood, 
		64 * vars->p_j, 64 * (vars->p_i + 1));
		return (0);
	}
	else if (vars->map.map[vars->p_i][vars->p_j] == 'N' && key == S)
	{
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood, 
		64 * vars->p_j, 64 * (vars->p_i - 1));
		return (0);
	}
	else if (vars->map.map[vars->p_i][vars->p_j] == 'N' && key == D)
	{
		image_set(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.blood, 
		64 * (vars->p_j - 1), 64 * vars->p_i);
		return (0);
	}
	return (1);
}

static void	set_variables(t_data *vars, int key)
{
	vars->stp++;
	if (vars->e == 0)
		image_set(vars);
	if(key == A && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerL, 
		64 * vars->p_j, 64 * vars->p_i);
	if(key == W && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerB, 
		64 * vars->p_j, 64 * vars->p_i);
	if(key == S && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 
		64 * vars->p_j, 64 * vars->p_i);
	if(key == D && vars->e == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.playerR, 
		64 * vars->p_j, 64 * vars->p_i);
	ft_printf("%d\n", vars->stp);
}

int	check_key(int key, t_data *vars)
{
	if (key == A && vars->map.map[vars->p_i][vars->p_j - 1] != '1' && vars->e == 0)
	{
		consumable(vars, key);
		vars->p_j--;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == W && vars->map.map[vars->p_i - 1][vars->p_j] != '1' && vars->e == 0)
	{
		consumable(vars, key);	
		vars->p_i--;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == S && vars->map.map[vars->p_i + 1][vars->p_j] != '1' && vars->e == 0)
	{	
		consumable(vars, key);
		vars->p_i++;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}
	else if (key == D && vars->map.map[vars->p_i][vars->p_j + 1] != '1' && vars->e == 0)
	{	
		consumable(vars, key);
		vars->p_j++;
		if (!enemy_check(vars, key))
			vars->e = 1;
		set_variables(vars, key);
	}					
	return (0);
}