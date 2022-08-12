/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:10:23 by mgranate          #+#    #+#             */
/*   Updated: 2022/08/12 15:22:18 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(const char *str)
{
	size_t	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && str[i] != '\n')
		;
	return (i);
}

int	check_line_end(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (buffer[i] != '\n');
}

void	ft_clean_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buff[i])
	{
		if (j == -1 && buff[i] == '\n')
			j = 0;
		else if (j >= 0)
			buff[j++] = buff[i];
		buff[i++] = 0;
	}
}

char	*ft_get_line(char *line, char *buff)
{
	int		i;
	int		j;	
	char	*temp;

	temp = line;
	i = 0;
	line = malloc(sizeof(char) * ft_strlen_get(buff) + ft_strlen_get(line) + 1);
	if (!line)
		return (0);
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	j = -1;
	while (buff[++j])
	{
		if (buff[j] == '\n')
			break ;
		line[i++] = buff[j];
	}
	line[i] = '\0';
	if (temp)
		free(temp);
	return (line);
}
