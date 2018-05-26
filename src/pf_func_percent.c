/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_func_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:38:10 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:34 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	pf_func_percent(t_pf_vars *vars, va_list *args)
{
	char	c;
	int		i;

	if (args)
		;
	c = '%';
	vars->olen = 1;
	pf_create_output(vars);
	i = 0;
	if (vars->options['-'])
	{
		vars->output[i] = '%';
		while (i < vars->width)
			vars->output[i++ + vars->olen] = ' ';
	}
	else
	{
		while (i < vars->width)
			vars->output[i++] = vars->options['0'] ? '0' : ' ';
		vars->output[i] = '%';
	}
	pf_write_output(vars);
}
