/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:45:20 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 17:34:22 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(char tipo, t_flag flags, va_list ap)
{
	if (tipo == 'c')
		return (ft_print_char(va_arg(ap, int), flags));
	else if (tipo == 's')
		return (ft_print_str(va_arg(ap, char *), flags));
	else if (tipo == 'd' || tipo == 'i')
		return (ft_print_nbr(va_arg(ap, int), flags));
	else if (tipo == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int), flags));
	else if (tipo == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), flags, 'x'));
	else if (tipo == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), flags, 'X'));
	else if (tipo == 'p')
		return (ft_print_ptr(va_arg(ap, void *), flags));
	else if (tipo == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (-1);
}
