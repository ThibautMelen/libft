/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:13:30 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:22:55 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && i < size)
		i++;
	if (i == size)
		return (0);
	return ((t_byte)str1[i] - (t_byte)str2[i]);
}
