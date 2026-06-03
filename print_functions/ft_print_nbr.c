/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:48:30 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 16:45:42 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	print_nbr(t_info_nbr info, t_flag flags);
static char	compute_sign(int n, t_flag flags);
static void	print_pad_and_nbr(t_info_nbr info);

int	ft_print_nbr(int n, t_flag flags)
{
	char		*raw_nbr;
	int			total_len;
	t_info_nbr	info;

	if (n == 0 && flags.dot && flags.precision == 0)
		return (0);
	info.sign = compute_sign(n, flags);
	raw_nbr = ft_itoa(n);
	if (n < 0)
		info.nbr = raw_nbr + 1;
	else
		info.nbr = raw_nbr;
	info.nbr_len = ft_strlen(info.nbr);
	info.count_zero_precision = 0;
	if (flags.dot && flags.precision > info.nbr_len)
		info.count_zero_precision = flags.precision - info.nbr_len;
	total_len = (info.sign != 0) + info.count_zero_precision + info.nbr_len;
	info.pad = flags.width - total_len;
	if (info.pad < 0)
		info.pad = 0;
	print_nbr(info, flags);
	free(raw_nbr);
	return (total_len + info.pad);
}

static char	compute_sign(int n, t_flag flags)
{
	if (n < 0)
		return ('-');
	if (flags.plus)
		return ('+');
	if (flags.space)
		return (' ');
	return (0);
}

static void	print_nbr(t_info_nbr info, t_flag flags)
{
	char	space;
	char	zero;

	space = 32;
	zero = '0';
	if (flags.minus)
	{
		print_pad_and_nbr(info);
		print_pad(info.pad, space);
	}
	else if (flags.zero && !flags.dot)
	{
		if (info.sign)
			write(1, &info.sign, 1);
		print_pad(info.pad, zero);
		write(1, info.nbr, info.nbr_len);
	}
	else
	{
		print_pad(info.pad, ' ');
		print_pad_and_nbr(info);
	}
}

static void	print_pad_and_nbr(t_info_nbr info)
{
	if (info.sign)
		write(1, &info.sign, 1);
	print_pad(info.count_zero_precision, '0');
	write(1, info.nbr, info.nbr_len);
}
