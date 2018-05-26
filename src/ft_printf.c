/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:23:49 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:24:03 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	t_pf_vars	vars;
	va_list		args;

	if (format == NULL)
		return (0);
	va_start(args, format);
	pf_init_vars(&vars);
	while (format[vars.pf] != '\0')
	{
		if (format[vars.pf] == '%')
		{
			pf_parse(format, &vars, &args);
			pf_reinit_vars(&vars);
		}
		else if (format[vars.pf] == '{')
			pf_parse_color(format, &vars, &args);
		else
			pf_write_buff((t_byte)format[vars.pf++], &vars);
		if (vars.len == -1)
			break ;
	}
	if (vars.pb > 0)
		pf_print_buff(&vars);
	return (vars.len);
}
