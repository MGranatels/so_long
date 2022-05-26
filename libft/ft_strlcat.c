/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:00:06 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/18 16:07:31 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst1;
	char	*src1;
	size_t	i;
	size_t	j;
	size_t	s;

	i = 0;
	j = 0;
	s = 0;
	src1 = (char *) src;
	dst1 = dst;
	i = ft_strlen(dst1);
	s = ft_strlen(src1);
	if (dstsize <= i)
		s += dstsize;
	else
		s += i;
	while (src[j] && (i + 1) < dstsize)
	{
		dst1[i] = src1[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (s);
}
