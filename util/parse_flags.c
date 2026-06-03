/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:22:23 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:09:00 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag_chars(const char *input, size_t *i, t_flag *flags);
void	parse_width(const char *input, size_t *i, t_flag *flags);
void	parse_precision(const char *input, size_t *i, t_flag *flags);

void	parse_flags(const char *input, size_t *i, t_flag *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	parse_flag_chars(input, i, flags);
	parse_width(input, i, flags);
	parse_precision(input, i, flags);
}

void	parse_flag_chars(const char *input, size_t *i, t_flag *flags)
{
	while (input[*i] == '-' || input[*i] == '0' || input[*i] == '#'
		|| input[*i] == '+' || input[*i] == ' ')
	{
		if (input[*i] == '-')
			flags->minus = 1;
		else if (input[*i] == '0')
			flags->zero = 1;
		else if (input[*i] == '#')
			flags->hash = 1;
		else if (input[*i] == '+')
			flags->plus = 1;
		else if (input[*i] == ' ')
			flags->space = 1;
		(*i)++;
	}
}

void	parse_width(const char *input, size_t *i, t_flag *flags)
{
	while (ft_isdigit(input[*i]))
	{
		flags->width = flags->width * 10 + (input[*i] - '0');
		(*i)++;
	}
}

void	parse_precision(const char *input, size_t *i, t_flag *flags)
{
	if (input[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		while (ft_isdigit(input[*i]))
		{
			flags->precision = flags->precision * 10 + (input[*i] - '0');
			(*i)++;
		}
	}
}
