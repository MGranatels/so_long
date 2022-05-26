/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/26 20:58:20 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close(int keycode, t_vars *vars)
{
	if (keycode == 27)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_data	*mlx;
	t_data	*win;
	t_img	*img;
	void	*mlx_hook;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_key_hook(win, close(), void *param);
	mlx_loop(mlx);
	
	return (0);
}