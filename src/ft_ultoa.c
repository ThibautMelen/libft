/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:53:53 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:23:25 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_nbrlen(uintmax_t nbr)
{
	int len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_ultoa(uintmax_t nbr)
{
	char	*str;
	int		len;

	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str += len - 1;
	while (nbr)
	{
		*str-- = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str + 1);
}
