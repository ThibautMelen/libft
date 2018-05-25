/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:36:27 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:16 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	set_value(uint64_t ptr, t_vars *vars)
{
	if (ptr == 0 && vars->precision == 0)
	{
		if (!(vars->value = ft_strdup("")))
			exit(-1);
	}
	else if (!(vars->value = ft_ultoa_base(ptr, 16)))
		exit(-1);
}

void		func_p(t_vars *vars, va_list *args)
{
	uint64_t	ptr;

	ptr = (uint64_t)va_arg(*args, void *);
	set_value(ptr, vars);
	vars->valen = ft_strlen(vars->value);
	if (!(vars->prefix = ft_strdup("0x")))
		exit(-1);
	vars->prlen = 2;
	if (vars->precision != -1 && (vars->precision =
			vars->precision - vars->valen) < 0)
		vars->precision = 0;
	vars->olen = vars->prlen + (vars->precision == -1 ? 0 : vars->precision)
		+ vars->valen;
	create_output(vars);
	format(vars);
	free(vars->value);
	vars->value = NULL;
	free(vars->prefix);
	vars->prefix = NULL;
	write_output(vars);
}
