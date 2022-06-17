/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:20:10 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/17 09:07:56 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

int	ft_close(int keycode, t_data *vars)
{
	if (keycode == EXIT)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (vars->map.clt == 0 && (vars->map.map[vars->p_i - 1][vars->p_j] == 'E'
		|| vars->map.map[vars->p_i + 1][vars->p_j] == 'E'
		|| vars->map.map[vars->p_i][vars->p_j + 1] == 'E'
		|| vars->map.map[vars->p_i][vars->p_j - 1] == 'E'
		|| vars->map.map[vars->p_i][vars->p_j] == 'E'))
	{
		vars->map.map[vars->e_i][vars->e_j] = 'D';
		set_variables(vars, keycode);
	}
	if (vars->p_i == vars->e_i && vars->p_j == vars->e_j)
	{
		vars->e = 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit_o,
			64 * vars->e_j, 64 * vars->e_i);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	define_numbers(t_data *vars)
{
	vars->nub.n0 = mlx_xpm_file_to_image(vars->mlx, "images/0.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n1 = mlx_xpm_file_to_image(vars->mlx, "images/1.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n2 = mlx_xpm_file_to_image(vars->mlx, "images/2.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n3 = mlx_xpm_file_to_image(vars->mlx, "images/3.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n4 = mlx_xpm_file_to_image(vars->mlx, "images/4.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n5 = mlx_xpm_file_to_image(vars->mlx, "images/5.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n6 = mlx_xpm_file_to_image(vars->mlx, "images/6.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n7 = mlx_xpm_file_to_image(vars->mlx, "images/7.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n8 = mlx_xpm_file_to_image(vars->mlx, "images/8.xpm",
			&vars->img.width, &vars->img.height);
	vars->nub.n9 = mlx_xpm_file_to_image(vars->mlx, "images/9.xpm",
			&vars->img.width, &vars->img.height);
}

static void	set_number(char nub, int i, t_data *vars)
{
	i = i + 1;
	if (nub == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n0, 35 * i, 20);
	if (nub == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n1, 35 * i, 20);
	if (nub == '2')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n2, 35 * i, 20);
	if (nub == '3')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n3, 35 * i, 20);
	if (nub == '4')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n4, 35 * i, 20);
	if (nub == '5')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n5, 35 * i, 20);
	if (nub == '6')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n6, 35 * i, 20);
	if (nub == '7')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n7, 35 * i, 20);
	if (nub == '8')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n8, 35 * i, 20);
	if (nub == '9')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->nub.n9, 35 * i, 20);
}

int	check_key_nub(t_data *vars)
{
	char	*nub;
	int		i;

	i = 0;
	nub = ft_itoa(vars->stp);
	define_numbers(vars);
	while (nub[i])
	{
		set_number(nub[i], i, vars);
		i++;
	}
	return (0);
}
