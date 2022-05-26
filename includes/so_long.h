#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

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
# define A 97
# define D 100
# define S 115
# define W 119
# define FOE "assets/foe.xpm"
# define PLAYER "assets/player.xpm"
# define EXIT 27


typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit_l;
	void	*player;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;

}				t_data;

#endif