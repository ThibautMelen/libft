/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:14:20 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:21:22 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdel(t_list **plist)
{
	t_list	*tmp;

	tmp = *plist;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	free(*plist);
	*plist = NULL;
}
