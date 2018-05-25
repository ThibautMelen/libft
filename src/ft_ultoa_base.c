/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:52:41 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:23:21 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_ultoa_base(uintmax_t nbr, uint8_t base)
{
	char		*symbols;
	char		*result;
	int			size;
	uintmax_t	lnbr;

	if (base < 2 || base > 35)
		return (ft_strdup("-1"));
	symbols = ft_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
	size = 1;
	lnbr = nbr;
	while (nbr /= base)
		size++;
	result = ft_strnew(size);
	while (size--)
	{
		result[size] = symbols[lnbr % base];
		lnbr /= base;
	}
	free(symbols);
	return (result);
}
