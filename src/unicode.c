/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:25:43 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 17:00:45 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	write_unicode(t_vars *vars, wchar_t wc, int s, int *i)
{
	if (s == 1)
		vars->output[(*i)++] = (t_byte)wc;
	else if (s == 2)
	{
		vars->output[(*i)++] = ((wc & 0x7C0) >> 6) | 0xC0;
		vars->output[(*i)++] = (wc & 0x3F) | 0x80;
	}
	else if (s == 3)
	{
		vars->output[(*i)++] = ((wc & 0xF000) >> 12) | 0xE0;
		vars->output[(*i)++] = ((wc & 0xFC0) >> 6) | 0x80;
		vars->output[(*i)++] = (wc & 0x3F) | 0x80;
	}
	else
	{
		vars->output[(*i)++] = ((wc & 0x1C0000) >> 18) | 0xF0;
		vars->output[(*i)++] = ((wc & 0x3F000) >> 12) | 0x80;
		vars->output[(*i)++] = ((wc & 0xFC0) >> 6) | 0x80;
		vars->output[(*i)++] = (wc & 0x3F) | 0x80;
	}
}

int		bin_size(wchar_t wc)
{
	int size;

	size = 1;
	if (MB_CUR_MAX == 1 && wc > 127 && wc < 256)
		return (size);
	while (wc /= 2)
		size++;
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}
