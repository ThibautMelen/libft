/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:42:21 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:23:03 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char *last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == chr)
			last = (char *)str;
		str++;
	}
	if (*str == chr)
		return ((char *)str);
	return (last);
}
