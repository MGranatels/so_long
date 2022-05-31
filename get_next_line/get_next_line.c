/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:38:46 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/31 19:51:51 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char static	buff[BUFFER_SIZE];
	char		*line;
	size_t		i;
	size_t		re;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	line = NULL;
	i = 1;
	while (i)
	{
		re = 1;
		if (!buff[0])
			re = read(fd, buff, BUFFER_SIZE);
		i = (check_line_end(buff) && re > 0);
		if (re > 0)
			line = ft_get_line(line, buff);
		ft_clean_buff(buff);
	}
	return (line);
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
// 		printf("Line %i: %s\n", i, str);
// 		printf("LENGHT = %lu\n", ft_strlen_get(str));
// 		if (!str)
// 			break ;
// 		free(str);
// 		i++;
// 	}
// }
