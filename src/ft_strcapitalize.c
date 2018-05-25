/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:24:15 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 18:39:47 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_strcapitalize(char *str)
{
	int		i;

	if (str == NULL)
		return ;
	str[0] = ft_toupper(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i - 1]) && ft_isalnum(str[i]))
			str[i] = ft_toupper(str[i]);
		else
			str[i] = ft_tolower(str[i]);
		i++;
	}
}
