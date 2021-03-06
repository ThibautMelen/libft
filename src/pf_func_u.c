/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:35:35 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:32 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static uintmax_t	get_nbr(t_pf_vars *vars, va_list *args)
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

void				pf_func_u(t_pf_vars *vars, va_list *args)
{
	uintmax_t	nbr;

	nbr = get_nbr(vars, args);
	if (nbr == 0 && vars->precision == 0)
	{
		if (!(vars->value = ft_strdup("")))
			exit(-1);
	}
	else if (!(vars->value = ft_ultoa(nbr)))
		exit(-1);
	vars->valen = ft_strlen(vars->value);
	if (vars->precision != -1 && (vars->precision =
			vars->precision - vars->valen) < 0)
		vars->precision = 0;
	vars->olen = (vars->precision == -1 ? 0 : vars->precision) + vars->valen;
	pf_create_output(vars);
	pf_format(vars);
	free(vars->value);
	pf_write_output(vars);
}
