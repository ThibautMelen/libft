/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_uu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:47:35 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:31 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	pf_func_uu(t_pf_vars *vars, va_list *args)
{
	vars->size = 'L';
	pf_func_u(vars, args);
}
