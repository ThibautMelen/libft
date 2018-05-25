/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:26:35 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:54 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	init_vars(t_vars *vars)
{
	int i;

	i = 0;
	vars->pb = 0;
	vars->pf = 0;
	vars->len = 0;
	vars->output = NULL;
	vars->order[0] = 'H';
	vars->order[1] = 'h';
	vars->order[2] = 'l';
	vars->order[3] = 'L';
	vars->order[4] = 'z';
	vars->order[5] = 'j';
	reinit_vars(vars);
}

void	reinit_vars(t_vars *vars)
{
	int i;

	i = 0;
	vars->size = 0;
	vars->width = 0;
	vars->precision = -1;
	vars->flag = 0;
	while (i < 49)
		vars->options[i++] = 0;
	if (vars->output != NULL)
	{
		free(vars->output);
		vars->output = NULL;
	}
	vars->olen = 0;
	vars->prefix = NULL;
	vars->prlen = 0;
	vars->value = NULL;
	vars->valen = 0;
	vars->negative = 0;
}
