/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:55:35 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:21:58 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *mem, int byte, size_t size)
{
	size_t len;

	len = size;
	while (size--)
		*(t_byte *)mem++ = (t_byte)byte;
	return (mem -= len);
}
