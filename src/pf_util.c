/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:21:06 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/26 13:17:20 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		pf_isflag(int type, char c)
{
	static char	*flags[] = { "+-#0 ", "%sSpdDioOuUxXcCn", "hlzj" };
	int			i;

	i = 0;
	while (flags[type][i] != '\0')
	{
		if (flags[type][i] == c)
			return (c);
		i++;
	}
	return (0);
}

void	pf_define_prefix(t_pf_vars *vars)
{
	vars->prlen = 1;
	if (vars->negative)
		vars->prefix = ft_strdup("-");
	else if (vars->options['+'])
		vars->prefix = ft_strdup("+");
	else if (vars->options[' '])
		vars->prefix = ft_strdup(" ");
	else
	{
		vars->prefix = NULL;
		vars->prlen = 0;
	}
}
