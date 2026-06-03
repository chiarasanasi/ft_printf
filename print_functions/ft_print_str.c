/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:30:37 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:07:24 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *s, int s_len, int pad, int minus);

int	ft_print_str(char *s, t_flag flags)
{
	int		s_len;
	int		pad;

	if (s == NULL)
		s = "(null)";
	s_len = ft_strlen(s);
	if (flags.dot && flags.precision < s_len)
		s_len = flags.precision;
	pad = flags.width - s_len;
	if (pad < 0)
		pad = 0;
	print_str(s, s_len, pad, flags.minus);
	return (s_len + pad);
}

void	print_str(char *s, int s_len, int pad, int minus)
{
	char	space;

	space = 32;
	if (minus)
	{
		write(1, s, s_len);
		while (pad > 0)
		{
			write(1, &space, 1);
			pad--;
		}
	}
	else
	{
		while (pad > 0)
		{
			write(1, &space, 1);
			pad--;
		}
		write(1, s, s_len);
	}
}
