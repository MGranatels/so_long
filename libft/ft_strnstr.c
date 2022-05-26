/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:04:54 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/27 16:40:18 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = ft_strlen(needle);
	h = (char *) haystack;
	n = (char *) needle;
	if (size == 0)
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] && i + j < len)
		{
			if (n[j + 1] == '\0')
				return (&h[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
