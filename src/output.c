/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:48:08 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:41 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	write_output(t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->olen + vars->width)
		write_buff(vars->output[i++], vars);
}

void	create_output(t_vars *vars)
{
	vars->width = vars->width - vars->olen;
	if (vars->width < 0)
		vars->width = 0;
	if (!(vars->output = (t_byte *)malloc(vars->olen + vars->width)))
		exit(-1);
}
