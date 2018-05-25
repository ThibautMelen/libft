/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:21:06 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:50 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		isflag(int type, char c)
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

void	define_prefix(t_vars *vars)
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
