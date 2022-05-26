/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/26 21:18:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == EXIT)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, ft_close, &vars);
	mlx_loop(vars.mlx);
}
// int	close(int keycode, mlx)
// {
// 	if (keycode == 27)
// 		mlx_destroy_window(mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	*mlx;
// 	t_data	*win;
// 	t_img	*img;
// 	void	*mlx_hook;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_key_hook(win, close(), void *param);
// 	mlx_loop(mlx);
	
// 	return (0);
// }