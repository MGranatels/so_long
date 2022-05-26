/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:31:47 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/25 20:07:38 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ls;

	ls = (t_list *)malloc(sizeof(*ls));
	if (!ls)
		return (NULL);
	ls->content = content;
	ls->next = NULL;
	return (ls);
}
