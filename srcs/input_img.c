/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:42 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/02 17:40:16 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	define_images(t_data *vars)
{
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, "images/gnmF.xpm", &vars->img.width, &vars->img.height);
	vars->img.playerL = mlx_xpm_file_to_image(vars->mlx, "images/ggnmL.xpm", &vars->img.width, &vars->img.height);
	vars->img.playerR = mlx_xpm_file_to_image(vars->mlx, "images/gnmR.xpm", &vars->img.width, &vars->img.height);
	vars->img.playerB = mlx_xpm_file_to_image(vars->mlx, "images/gnmB.xpm", &vars->img.width, &vars->img.height);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, "images/wall3.xpm", &vars->img.width, &vars->img.height);
	vars->img.path = mlx_xpm_file_to_image(vars->mlx, "images/Ground4.xpm", &vars->img.width, &vars->img.height);
	vars->img.exit_l = mlx_xpm_file_to_image(vars->mlx, "images/exit.xpm", &vars->img.width, &vars->img.height);
	vars->img.clt = mlx_xpm_file_to_image(vars->mlx, "images/Collectable.xpm", &vars->img.width, &vars->img.height);
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
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.path, 64 * j, 64 * i);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, 64 * j, 64 * i);
			}
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.path, 64 * j, 64 * i);
			if (vars->map.map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit_l, 64 * j, 64 * i);
			if (vars->map.map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.clt, 64 * j, 64 * i);
			j++;
		}		
		i++;
	}
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 64 * vars->p_j, 64 * vars->p_i);
}