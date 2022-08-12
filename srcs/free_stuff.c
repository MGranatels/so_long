/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:31:28 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/08/12 19:00:57 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_data *vars)
{
	int	i;

	i = 0;
	if (!vars->map.map)
		return ;
	while (vars->map.map[i])
	{
		free(vars->map.map[i]);
		i++;
	}
	free(vars->map.map[i]);
	free(vars->map.map);
}

void	free_images(t_data *vars)
{
	if (vars->nub.frame)
		mlx_destroy_image(vars->mlx, vars->nub.frame);
	if (vars->nub.n0)
		mlx_destroy_image(vars->mlx, vars->nub.n0);
	if (vars->nub.n1)
		mlx_destroy_image(vars->mlx, vars->nub.n1);
	if (vars->nub.n2)
		mlx_destroy_image(vars->mlx, vars->nub.n2);
	if (vars->nub.n3)
		mlx_destroy_image(vars->mlx, vars->nub.n3);
	if (vars->nub.n4)
		mlx_destroy_image(vars->mlx, vars->nub.n4);
	if (vars->nub.n5)
		mlx_destroy_image(vars->mlx, vars->nub.n5);
	if (vars->nub.n6)
		mlx_destroy_image(vars->mlx, vars->nub.n6);
	if (vars->nub.n7)
		mlx_destroy_image(vars->mlx, vars->nub.n7);
	if (vars->nub.n8)
		mlx_destroy_image(vars->mlx, vars->nub.n8);
	if (vars->nub.n9)
		mlx_destroy_image(vars->mlx, vars->nub.n9);
	if (vars->img.clt)
		mlx_destroy_image(vars->mlx, vars->img.clt);
	if (vars->img.player)
		mlx_destroy_image(vars->mlx, vars->img.player);
	if (vars->img.playerl)
		mlx_destroy_image(vars->mlx, vars->img.playerl);
	if (vars->img.playerr)
		mlx_destroy_image(vars->mlx, vars->img.playerr);
	if (vars->img.playerb)
		mlx_destroy_image(vars->mlx, vars->img.playerb);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (vars->img.path)
		mlx_destroy_image(vars->mlx, vars->img.path);
	if (vars->img.exit_l)
		mlx_destroy_image(vars->mlx, vars->img.exit_l);
	if (vars->img.exit_o)
		mlx_destroy_image(vars->mlx, vars->img.exit_o);
	if (vars->img.blood)
		mlx_destroy_image(vars->mlx, vars->img.blood);
	if (vars->img.eny)
		mlx_destroy_image(vars->mlx, vars->img.eny);
}

void	free_mlx(t_data *vars)
{
	printf("DEBUUGG\n");
	free_map(vars);
	free_images(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
