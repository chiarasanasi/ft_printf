/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:48:30 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:07:55 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_unsigned(t_info_nbr info, t_flag flags);

int	ft_print_unsigned(unsigned int n, t_flag flags)
{
	int			total_len;
	t_info_nbr	info;

	if (n == 0 && flags.dot && flags.precision == 0)
		return (0);
	info.nbr = ft_utoa(n);
	info.nbr_len = ft_strlen(info.nbr);
	info.count_zero_precision = 0;
	if (flags.dot && flags.precision > info.nbr_len)
		info.count_zero_precision = flags.precision - info.nbr_len;
	total_len = info.count_zero_precision + info.nbr_len;
	info.pad = flags.width - total_len;
	if (info.pad < 0)
		info.pad = 0;
	print_unsigned(info, flags);
	free(info.nbr);
	return (total_len + info.pad);
}

static void	print_unsigned(t_info_nbr info, t_flag flags)
{
	char	space;
	char	zero;

	space = 32;
	zero = '0';
	if (flags.minus)
	{
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
		print_pad(info.pad, space);
	}
	else if (flags.zero && !flags.dot)
	{
		print_pad(info.pad, zero);
		write(1, info.nbr, info.nbr_len);
	}
	else
	{
		print_pad(info.pad, ' ');
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
	}
}
