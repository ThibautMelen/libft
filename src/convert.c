/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:28:46 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:28:35 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static t_func	g_funcs[] = {
	{ &func_percent, '%' },
	{ &func_s, 's' },
	{ &func_ss, 'S' },
	{ &func_p, 'p' },
	{ &func_d, 'd' },
	{ &func_dd, 'D' },
	{ &func_i, 'i' },
	{ &func_o, 'o' },
	{ &func_oo, 'O' },
	{ &func_u, 'u' },
	{ &func_uu, 'U' },
	{ &func_x, 'x' },
	{ &func_xx, 'X' },
	{ &func_c, 'c' },
	{ &func_cc, 'C' },
	{ &func_n, 'n' }
};

void	convert(t_vars *vars, va_list *args)
{
	int i;

	i = 0;
	while (i < (int)sizeof(g_funcs))
	{
		if (g_funcs[i].flag == vars->flag)
		{
			g_funcs[i].call(vars, args);
			break ;
		}
		i++;
	}
}
