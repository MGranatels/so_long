/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:28 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/27 16:37:19 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst1 = dst;
	src1 = (unsigned char *) src;
	if (dst1 > src1)
		while (len--)
			dst1[len] = src1[len];
	else
	{
		while (len--)
		{
			*dst1 = *src1;
			dst1++;
			src1++;
		}
	}
	return (dst);
}
