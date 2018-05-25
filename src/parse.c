/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:06:14 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 16:29:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	set_size(t_vars *vars, char tmp)
{
	int			j;
	int			k;

	j = 0;
	k = 0;
	if (vars->size)
	{
		while (j < 6)
			if (vars->order[j++] == vars->size)
				break ;
	}
	while (k < 6)
		if (vars->order[k++] == tmp)
			break ;
	if (k > j)
		vars->size = tmp;
}

static void	parse_size(const char *format, t_vars *vars, int *i)
{
	char	tmp;

	tmp = format[*i];
	if (tmp == 'h' && format[*i + 1] == 'h')
	{
		tmp = 'H';
		(*i)++;
	}
	else if (tmp == 'l' && format[*i + 1] == 'l')
	{
		tmp = 'L';
		(*i)++;
	}
	set_size(vars, tmp);
}

static void	parse_precision(const char *format, t_vars *vars, va_list *args,
							int *i)
{
	int p;

	p = 0;
	vars->precision = 0;
	if (format[*i + 1] == '*')
	{
		p = va_arg(*args, int);
		if (p < 0)
			p = -1;
		(*i)++;
	}
	else
	{
		if (ft_isdigit(format[*i + 1]))
		{
			while (ft_isdigit(format[++(*i)]))
			{
				p *= 10;
				p += format[*i] - '0';
			}
			(*i)--;
		}
	}
	vars->precision = p;
}

static void	parse_width(const char *format, t_vars *vars, va_list *args, int *i)
{
	int p;

	p = 0;
	if (format[*i] == '*')
	{
		p = va_arg(*args, int);
		if (p < 0)
		{
			vars->options['-'] = 1;
			p = -p;
		}
	}
	else
	{
		while (ft_isdigit(format[*i]))
		{
			p *= 10;
			p += format[*i] - '0';
			(*i)++;
		}
		(*i)--;
	}
	vars->width = p;
}

void		parse(const char *format, t_vars *vars, va_list *args)
{
	int	i;

	i = ++vars->pf;
	while (!(vars->flag = isflag(1, format[i])))
	{
		if (isflag(0, format[i]))
			vars->options[(int)format[i]] = 1;
		else if (isflag(2, format[i]))
			parse_size(format, vars, &i);
		else if (format[i] == '.')
			parse_precision(format, vars, args, &i);
		else if (ft_isdigit(format[i]) || format[i] == '*')
			parse_width(format, vars, args, &i);
		else
			break ;
		i++;
	}
	vars->pf = i + (format[i] != 0);
	if (vars->flag == 0)
	{
		if (format[i] != '\0')
			alt_func_c(vars, format[i]);
		return ;
	}
	convert(vars, args);
}
