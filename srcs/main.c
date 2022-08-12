/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/08/12 19:15:01 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	iniciate_variables(t_data *vars)
{
	vars->img.mlx_img = NULL;
	vars->img.wall = NULL;
	vars->img.clt = NULL;
	vars->img.exit_l = NULL;
	vars->img.exit_o = NULL;
	vars->img.player = NULL;
	vars->img.playerr = NULL;
	vars->img.playerl = NULL;
	vars->img.playerb = NULL;
	vars->img.blood = NULL;
	vars->img.eny = NULL;
	vars->img.path = NULL;
	vars->img.win_w = NULL;
	vars->img.win_b = NULL;
	vars->nub.n0 = NULL;
	vars->nub.n1 = NULL;
	vars->nub.n2 = NULL;
	vars->nub.n3 = NULL;
	vars->nub.n4 = NULL;
	vars->nub.n5 = NULL;
	vars->nub.n6 = NULL;
	vars->nub.n7 = NULL;
	vars->nub.n8 = NULL;
	vars->nub.n9 = NULL;
}

static void	player_pos(t_data *vars)
{
	int	i;
	int	j;
	int	b00l;

	i = 0;
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

	if (ac == 2)
	{
		vars.e = 0;
		vars.win_width = 0;
		vars.win_height = 0;
		if (!map_making(av[1], &vars))
		{
			free_map(&vars);
			return (0);
		}
		vars.win_width += 1;
		vars.win_height += 1;
		iniciate_variables(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, (64 * vars.win_width),
				(64 * vars.win_height), "Ghiga World");
		player_pos(&vars);
		define_images(&vars);
		define_numbers(&vars);
		image_set(&vars);
		mlx_hook(vars.win, 2, 1l << 0, check_key, &vars);
		mlx_hook(vars.win, 17, 1l << 2, close_window, &vars);
		mlx_key_hook(vars.win, ft_close, &vars);
		mlx_loop(vars.mlx);
	}
}
