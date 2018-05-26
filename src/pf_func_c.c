/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:19:07 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:41 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	fill(t_pf_vars *vars, char c)
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

void		pf_alt_func_c(t_pf_vars *vars, char c)
{
	vars->olen = 1;
	pf_create_output(vars);
	fill(vars, c);
	pf_write_output(vars);
}

void		pf_func_c(t_pf_vars *vars, va_list *args)
{
	char	c;

	if (vars->size == 'l')
	{
		pf_func_cc(vars, args);
		return ;
	}
	c = (char)va_arg(*args, int);
	pf_alt_func_c(vars, c);
}
