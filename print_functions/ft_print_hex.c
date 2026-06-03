/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:47:28 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:01:05 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(t_info_nbr info, t_flag flags, char x);
static void	emit_prefix(t_flag flags, char x);
static char	*get_base(char x);

int	ft_print_hex(unsigned int n, t_flag flags, char x)
{
	int			total_len;
	char		*base;
	t_info_nbr	info;
	int			prefix_len;

	prefix_len = 0;
	if (flags.hash && n == 0)
		flags.hash = 0;
	if (flags.hash)
		prefix_len = 2;
	base = get_base(x);
	if (n == 0 && flags.dot && flags.precision == 0)
		return (0);
	info.nbr = ft_itoa_hex(n, base);
	info.nbr_len = ft_strlen(info.nbr);
	info.count_zero_precision = 0;
	if (flags.dot && flags.precision > info.nbr_len)
		info.count_zero_precision = flags.precision - info.nbr_len;
	total_len = prefix_len + info.count_zero_precision + info.nbr_len;
	info.pad = flags.width - total_len;
	if (info.pad < 0)
		info.pad = 0;
	print_hex(info, flags, x);
	free(info.nbr);
	return (total_len + info.pad);
}

static char	*get_base(char x)
{
	if (x == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static void	print_hex(t_info_nbr info, t_flag flags, char x)
{
	if (flags.minus)
	{
		emit_prefix(flags, x);
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
		print_pad(info.pad, ' ');
	}
	else if (flags.zero && !flags.dot)
	{
		emit_prefix(flags, x);
		print_pad(info.pad, '0');
		write(1, info.nbr, info.nbr_len);
	}
	else
	{
		print_pad(info.pad, ' ');
		emit_prefix(flags, x);
		print_pad(info.count_zero_precision, '0');
		write(1, info.nbr, info.nbr_len);
	}
}

static void	emit_prefix(t_flag flags, char x)
{
	if (!flags.hash)
		return ;
	if (x == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}
