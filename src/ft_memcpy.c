/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:25:08 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:21:52 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t len;

	len = size;
	while (size--)
		*(t_byte *)dest++ = *(t_byte *)src++;
	return (dest -= len);
}
