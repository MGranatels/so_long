/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:31:28 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/06/16 17:34:35 by anne-sophie      ###   ########.fr       */
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

void    free_mlx(t_data *vars)
{
    free(vars->win);
    free(vars->mlx);
}
