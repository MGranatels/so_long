/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:26 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/31 21:59:03 by mgranate         ###   ########.fr       */
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
	int	i;
	int	j;

	ft_printf("KEY == %d\n", key);
	i = 0;
	j = 0;
	int k;
	k=0;
	if (key == A)
	{
		vars->map.map[vars->p_i][vars->p_j] = '0';
		vars->map.map[vars->p_i][vars->p_j - 1] = 'P';
		vars->p_j--;
		while (vars->map.map[k])
		{
			ft_printf("Vars[map] == %s",vars->map.map[k]);
			k++;
		}
		return(1);
	}	
	return (0);
}