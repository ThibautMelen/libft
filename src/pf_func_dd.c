/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_dd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:34:44 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:38 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	pf_func_dd(t_pf_vars *vars, va_list *args)
{
	vars->size = 'L';
	pf_func_d(vars, args);
}
