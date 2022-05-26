/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:06:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/27 16:22:43 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_lenght(long n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_int_lenght(n / 10));
}

char	*ft_itoa(int n)
{
	char	*trn;
	int		len;
	int		i;
	int		nb;

	nb = n;
	trn = 0;
	len = ft_int_lenght(n) + 1 + (n < 0);
	trn = (char *)malloc(sizeof(char) * (len));
	if (!trn)
		return (NULL);
	trn[len - 1] = '\0';
	i = len -2;
	while (i >= 0)
	{
		trn[i] = (n % 10) * ((n > 0) - (n < 0)) + '0';
		n /= 10;
		i--;
	}
	if (nb < 0)
		trn[0] = '-';
	return (trn);
}
