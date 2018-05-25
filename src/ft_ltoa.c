/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:40:11 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:21:39 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_nbrlen(intmax_t nbr)
{
	int len;

	len = (nbr < 0) ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_ltoa(intmax_t nbr)
{
	char	*str;
	int		len;
	int		neg;

	if (nbr == INT64_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(nbr);
	if ((neg = (nbr < 0)))
		nbr = -nbr;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str += len - 1;
	while (nbr)
	{
		*str-- = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		*str-- = '-';
	return (str + 1);
}
