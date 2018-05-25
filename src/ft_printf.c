/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:23:49 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:30:21 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf(const char *format, ...)
{
	t_vars		vars;
	va_list		args;

	if (format == NULL)
		return (0);
	va_start(args, format);
	init_vars(&vars);
	while (format[vars.pf] != '\0')
	{
		if (format[vars.pf] == '%')
		{
			parse(format, &vars, &args);
			reinit_vars(&vars);
		}
		else if (format[vars.pf] == '{')
			parse_color(format, &vars, &args);
		else
			write_buff((t_byte)format[vars.pf++], &vars);
		if (vars.len == -1)
			break ;
	}
	if (vars.pb > 0)
		print_buff(&vars);
	return (vars.len);
}
