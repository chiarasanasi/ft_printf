/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:39:41 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 17:34:58 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, int pad, t_flag flags);

int	ft_print_char(int c, t_flag flags)
{
	int		pad;

	pad = 0;
	if (flags.width > 1)
		pad = flags.width - 1;
	print_char(c, pad, flags);
	return (pad + 1);
}

void	print_char(int c, int pad, t_flag flags)
{
	char	space;

	space = 32;
	if (flags.minus == 1)
	{
		write(1, &c, 1);
		while (pad != 0)
		{
			write(1, &space, 1);
			pad--;
		}
	}
	else
	{
		while (pad != 0)
		{
			write(1, &space, 1);
			pad--;
		}
		write(1, &c, 1);
	}
}
