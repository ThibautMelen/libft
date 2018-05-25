/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:10:08 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:09 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static uintmax_t	get_nbr(t_vars *vars, va_list *args)
{
	if (vars->size == 0)
		return (va_arg(*args, uint32_t));
	else if (vars->size == 'h')
		return ((uint16_t)va_arg(*args, uint32_t));
	else if (vars->size == 'H')
		return ((uint8_t)va_arg(*args, uint32_t));
	else if (vars->size == 'l')
		return (va_arg(*args, unsigned long));
	else if (vars->size == 'L')
		return (va_arg(*args, uint64_t));
	else if (vars->size == 'j')
		return (va_arg(*args, uintmax_t));
	else if (vars->size == 'z')
		return (va_arg(*args, size_t));
	return (va_arg(*args, uint32_t));
}

static void			set_value(uintmax_t nbr, t_vars *vars)
{
	if (nbr == 0 && vars->precision == 0)
	{
		if (!(vars->value = ft_strdup("")))
			exit(-1);
	}
	else if (!(vars->value = ft_ultoa_base(nbr, 8)))
		exit(-1);
}

void				func_o(t_vars *vars, va_list *args)
{
	uintmax_t	nbr;

	nbr = get_nbr(vars, args);
	set_value(nbr, vars);
	vars->valen = ft_strlen(vars->value);
	if (vars->options['#'] && !(nbr == 0 && vars->precision == -1))
	{
		if (!(vars->prefix = ft_strdup("0")))
			exit(-1);
		vars->prlen = 1;
	}
	if (vars->precision != -1 && (vars->precision =
			vars->precision - vars->valen - vars->prlen) < 0)
		vars->precision = 0;
	vars->olen = vars->prlen + (vars->precision == -1 ? 0 : vars->precision)
		+ vars->valen;
	create_output(vars);
	format(vars);
	if (vars->prlen > 0)
		free(vars->prefix);
	free(vars->value);
	write_output(vars);
}
