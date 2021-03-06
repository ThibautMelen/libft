/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:33:11 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 18:40:51 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(const void *content, size_t size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(list->content = malloc(size * sizeof(*content))))
			return (NULL);
		ft_memcpy(list->content, content, size);
		list->size = size;
	}
	else
	{
		list->content = NULL;
		list->size = 0;
	}
	list->next = NULL;
	return (list);
}
