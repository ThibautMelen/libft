/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:34:11 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:28:26 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	write_buff(t_byte byte, t_vars *vars)
{
	vars->buff[vars->pb] = byte;
	vars->pb++;
	vars->len++;
	if (vars->pb == BUFF_SIZE)
		print_buff(vars);
}

void	print_buff(t_vars *vars)
{
	write(1, vars->buff, vars->pb);
	ft_bzero(vars->buff, vars->pb);
	vars->pb = 0;
}
