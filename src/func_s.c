/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:49:24 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:23 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	fill_right(t_vars *vars, char *str)
{
	int i;

	i = 0;
	while (i < vars->olen)
	{
		vars->output[i] = str[i];
		i++;
	}
	i = 0;
	while (i < vars->width)
		vars->output[i++ + vars->olen] = ' ';
}

static void	fill_left(t_vars *vars, char *str)
{
	int i;

	i = 0;
	while (i < vars->width)
		vars->output[i++] = vars->options['0'] ? '0' : ' ';
	i = 0;
	while (i < vars->olen)
	{
		vars->output[i + vars->width] = str[i];
		i++;
	}
}

void		func_s(t_vars *vars, va_list *args)
{
	char	*str;

	if (vars->size == 'l')
	{
		func_ss(vars, args);
		return ;
	}
	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	vars->olen = ft_strlen(str);
	if (vars->precision > -1 && vars->olen > vars->precision)
		vars->olen = vars->precision;
	create_output(vars);
	if (vars->options['-'])
		fill_right(vars, str);
	else
		fill_left(vars, str);
	write_output(vars);
}
