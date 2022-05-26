/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:10:23 by mgranate          #+#    #+#             */
/*   Updated: 2022/05/26 19:12:13 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
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
	line = malloc(sizeof(char) * ft_strlen(buff) + ft_strlen(line) + 1);
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		line[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (temp)
		free(temp);
	return (line);
}
