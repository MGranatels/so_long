/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:42 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/01 00:17:18 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	define_images(t_data *vars)
{
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, "images/char.xpm", &vars->img.width, &vars->img.height);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, "images/Tree.xpm", &vars->img.width, &vars->img.height);
	vars->img.path = mlx_xpm_file_to_image(vars->mlx, "images/Ground.xpm", &vars->img.width, &vars->img.height);
}


void	image_set(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, 64 * j, 64 * i);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.path, 64 * j, 64 * i);
			j++;
		}		
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 64 * vars->p_j, 64 * vars->p_i);
}