/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:47:09 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:28:38 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	putprefix(t_vars *vars, int i)
{
	int j;

	j = 0;
	while (j < vars->prlen)
		vars->output[i++] = vars->prefix[j++];
	return (i);
}

static int	putprecision(t_vars *vars, int i)
{
	int j;

	j = -1;
	while (++j < vars->precision)
		vars->output[i++] = '0';
	return (i);
}

static int	putvalue(t_vars *vars, int i)
{
	int j;

	j = 0;
	while (j < vars->valen)
		vars->output[i++] = vars->value[j++];
	return (i);
}

static int	putwidth(t_vars *vars, char c, int i)
{
	int j;

	j = -1;
	while (++j < vars->width)
		vars->output[i++] = c;
	return (i);
}

void		format(t_vars *vars)
{
	int i;

	i = 0;
	if (vars->options['-'])
		putwidth(vars, ' ', putvalue(vars, putprecision(vars,
			putprefix(vars, 0))));
	else
	{
		if (vars->precision == -1)
		{
			if (vars->options['0'])
				putvalue(vars, putwidth(vars, '0', putprefix(vars, 0)));
			else
				putvalue(vars, putprefix(vars, putwidth(vars, ' ', 0)));
		}
		else
			putvalue(vars, putprecision(vars, putprefix(vars,
				putwidth(vars, ' ', 0))));
	}
}
