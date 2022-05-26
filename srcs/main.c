/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/26 20:01:36 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data *mlx;
	char **split;
	
	ft_printf("Hello World");
	mlx = mlx_init();
	split = ft_split("hello world", 'w');
	
	return (0);
}