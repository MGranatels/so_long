/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:41:47 by mgranate          #+#    #+#             */
/*   Updated: 2022/06/15 19:13:16 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0
# define IMG_SIZE 48
# define TITRE "Treasure"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"
# define PEACH "\033[38;5;217m"
# define ARROW_TOP 65362
# define ARROW_BOT 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define A 0
# define D 2
# define S 1
# define W 13
# define FOE "assets/foe.xpm"
# define PLAYER "images/char2.xpm"
# define EXIT 53
# define KEYPRESS 2

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	char	*path;
	char	**map;
	int		can_exit;
	int		clt;

}				t_map;
typedef struct s_nub
{
	void	*frame;
	void	*n0;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;

}	t_nub;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*clt;
	void	*exit_l;
	void	*exit_o;
	void	*player;
	void	*playerr;
	void	*playerl;
	void	*playerb;
	void	*blood;
	void	*eny;
	void	*path;
	void	*win_w;
	void	*win_b;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		stp;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		i;
	int		j;
	int		e;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
	t_nub	nub;
}				t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

void	image_set(t_data *vars);
void	define_images(t_data *vars);
void	set_variables(t_data *vars, int key);
void	define_numbers(t_data *vars);
void	consumable(t_data *vars, int key);

int		check_key(int key, t_data *vars);
int		check_key_nub(t_data *vars);
int		map_width(char *map, t_data	*vars);
int		ft_close(int keycode, t_data *vars);

//enemy key check
int		key_a_check(t_data *vars);
int		key_w_check(t_data *vars);
int		key_s_check(t_data *vars);
int		key_d_check(t_data *vars);
int		close_window(t_data *vars);

#endif