/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:19:07 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:30:03 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	fill(t_vars *vars, char c)
{
	int i;

	i = 0;
	if (vars->options['-'])
	{
		vars->output[i] = c;
		while (i < vars->width)
			vars->output[i++ + vars->olen] = ' ';
	}
	else
	{
		while (i < vars->width)
			vars->output[i++] = vars->options['0'] ? '0' : ' ';
		vars->output[i] = c;
	}
}

void		alt_func_c(t_vars *vars, char c)
{
	vars->olen = 1;
	create_output(vars);
	fill(vars, c);
	write_output(vars);
}

void		func_c(t_vars *vars, va_list *args)
{
	char	c;

	if (vars->size == 'l')
	{
		func_cc(vars, args);
		return ;
	}
	c = (char)va_arg(*args, int);
	alt_func_c(vars, c);
}
