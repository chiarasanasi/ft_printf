/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:50:22 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:06:11 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr(t_info_nbr info, t_flag flags);

int	ft_print_ptr(void *p, t_flag flags)
{
	unsigned long	n;
	int				total_len;
	char			*base;
	t_info_nbr		info;

	if (p == NULL)
	{
		flags.dot = 0;
		flags.precision = 0;
		return (ft_print_str("(nil)", flags));
	}
	n = (unsigned long)p;
	base = "0123456789abcdef";
	info.nbr = ft_ultoa_hex(n, base);
	info.nbr_len = ft_strlen(info.nbr);
	info.count_zero_precision = 0;
	if (flags.dot && flags.precision > info.nbr_len)
		info.count_zero_precision = flags.precision - info.nbr_len;
	total_len = 2 + info.count_zero_precision + info.nbr_len;
	info.pad = flags.width - total_len;
	if (info.pad < 0)
		info.pad = 0;
	print_ptr(info, flags);
	free(info.nbr);
	return (total_len + info.pad);
}

static void	print_ptr(t_info_nbr info, t_flag flags)
{
	char	*hashchar;

	hashchar = "0x";
	if (flags.minus)
	{
		write(1, "0x", 2);
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
		print_pad(info.pad, ' ');
	}
	else if (flags.zero && !flags.dot)
	{
		write(1, hashchar, 2);
		print_pad(info.pad, '0');
		write(1, info.nbr, info.nbr_len);
	}
	else
	{
		print_pad(info.pad, ' ');
		write(1, hashchar, 2);
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
	}
}
