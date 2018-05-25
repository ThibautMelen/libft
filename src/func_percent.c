/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:38:10 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:20 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	func_percent(t_vars *vars, va_list *args)
{
	char	c;
	int		i;

	if (args)
		;
	c = '%';
	vars->olen = 1;
	create_output(vars);
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
	write_output(vars);
}
