/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:57:45 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:06 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	func_n(t_vars *vars, va_list *args)
{
	int	*ptr;

	ptr = va_arg(*args, int *);
	if (ptr != NULL)
		*ptr = vars->len;
}
