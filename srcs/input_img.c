/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:42 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/30 12:17:55 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	define_images(t_data *vars)
{
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, "images/char.xpm", &vars->img.width, &vars->img.height);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, "images/Tree.xpm", &vars->img.width, &vars->img.height);
	vars->img.path = mlx_xpm_file_to_image(vars->mlx, "images/Ground.xpm", &vars->img.width, &vars->img.height);
}


void	image_set(char *map, t_data *vars)
{
	char    *line;
    int     fd;

	line = NULL;
	vars->j = 0;
    fd = open(map, O_RDONLY);
	while (1)
	{
		vars->i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[vars->i] != '\n' && line[vars->i])
		{
			if (line[vars->i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall, 64 * vars->i, 64 * vars->j);
			else	
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.path, 64 * vars->i, 64 * vars->j);
			if (line[vars->i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, 64 * vars->i, 64 * vars->j);
			vars->i++;
		}		
		vars->j++;
	}
}