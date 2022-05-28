/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/28 19:01:25 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	ft_close(int keycode, t_data vars)
{
	(void) vars;
	if (keycode == EXIT)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		free(vars.mlx);
	}
	return (0);
}

int	main( int ac, char **av)
{
	t_data	vars;

	vars.win_width = 0;
	if(ac == 2)
	{
		vars.win_width = map_width(av[1], vars);
		ft_printf("Width = %d\n", vars.win_width);
	}
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// mlx_key_hook(vars.win, ft_close, vars.mlx);
	// mlx_loop(vars.mlx);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;

// 	i = 1;
// 	fd = open("read", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		printf("Line %i: %s", i, str);
// 		if (!str)
// 			break ;
// 		free(str);
// 		i++;
// 	}
// }
