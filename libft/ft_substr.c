/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:44:08 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/25 19:59:16 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	check_len(size_t len, char const *s)
{
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	i2;
	char	*s1;

	i = 0;
	i2 = 0;
	len = check_len(len, s);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (!s)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (s1 == NULL)
		return (0);
	while (s[i])
	{
		if (i >= start && i2 < len)
		{
			s1[i2] = s[i];
			i2++;
		}
		i++;
	}
	s1[i2] = 0;
	return (s1);
}
