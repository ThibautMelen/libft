/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:57:45 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:37 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	pf_func_n(t_pf_vars *vars, va_list *args)
{
	int	*ptr;

	ptr = va_arg(*args, int *);
	if (ptr != NULL)
		*ptr = vars->len;
}
