/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_oo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:41:42 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:13 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	func_oo(t_vars *vars, va_list *args)
{
	vars->size = 'L';
	func_o(vars, args);
}