/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/02 18:34:03 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_pos(t_data *vars)
{
	int	i;
	int	j;
	int	b00l;
	
	i = 0;
	j = 0;
	b00l = 0;
	vars->stp = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'P' && b00l == 0)
			{
				vars->p_i = i;
				vars->p_j = j;
				printf("Hight cord: j== %d i == %d\n", (vars->p_j), vars->p_i);
				b00l = 1;
				vars->map.map[i][j] = '0';
			}
			else if (vars->map.map[i][j] == 'P' && b00l == 1)
				vars->map.map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	main( int ac, char **av)
{
	t_data	vars;
	t_img	*img;
	
	if (ac == 2)
	{
		img = NULL;
		vars.win_width = 0;
		if (!map_width(av[1], &vars))
			return (0);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, (64 * vars.win_width), (64 * vars.win_height), "My Game");
		player_pos(&vars);
		define_images(&vars);
		image_set(&vars);
		mlx_hook(vars.win, KEYPRESS, 0, &check_key , &vars);
		mlx_key_hook(vars.win, ft_close, &vars);
		mlx_loop(vars.mlx);
	}
}
