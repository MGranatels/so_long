/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/29 20:23:54 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	ft_close(int keycode, t_data *vars)
{
	(void) vars;
	if (keycode == EXIT)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main( int ac, char **av)
{
	t_data	vars;
	t_img	*img;
	
	img = NULL;
	vars.win_width = 0;
	if(ac == 2)
	{
		if (!map_width(av[1], &vars))
			return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (64 * vars.win_width), (64 * vars.win_height), "My Game");
	define_images(&vars);
	image_set(av[1], &vars);
	mlx_key_hook(vars.win, ft_close, &vars);
	ft_printf("window size = %d\n", vars.win_width);
	ft_printf("window height = %d\n", vars.win_height);
	mlx_loop(vars.mlx);
}

// int main ()
// {
// 	void *mlx;
// 	void *win;
	
// 	mlx = mlx_init();
	
// 	win = mlx_new_window()
// }
