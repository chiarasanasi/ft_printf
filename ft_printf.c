/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:14 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 17:36:10 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		res_count(const char *input, size_t *i, va_list ap);
void	parse_flags(const char *input, size_t *i, t_flag *flags);

int	ft_printf(const char *input, ...)
{
	size_t	i;
	int		count;
	int		res;
	va_list	ap;

	if (!input)
		return (-1);
	va_start(ap, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		res = res_count(input, &i, ap);
		if (res == -1)
		{
			va_end(ap);
			return (-1);
		}
		count = count + res;
	}
	va_end(ap);
	return (count);
}

int	res_count(const char *input, size_t *i, va_list ap)
{
	int		res;
	t_flag	flags;

	if (input[*i] == '%')
	{
		if (input[*i + 1] == '\0')
			return (-1);
		(*i)++;
		parse_flags(input, i, &flags);
		res = ft_dispatch(input[*i], flags, ap);
		(*i)++;
		return (res);
	}
	write(1, &input[*i], 1);
	(*i)++;
	return (1);
}
