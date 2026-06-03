/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:31:18 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/03 15:18:20 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_flag
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flag;
typedef struct s_info_nbr
{
	char	*nbr;
	int		nbr_len;
	int		count_zero_precision;
	int		pad;
	char	sign;
}	t_info_nbr;
int		ft_printf(const char *input, ...);
void	parse_flags(const char *input, size_t *i, t_flag *flags);
int		ft_dispatch(char tipo, t_flag flags, va_list ap);
int		ft_print_char(int c, t_flag flags);
int		ft_print_str(char *s, t_flag flags);
int		ft_print_nbr(int n, t_flag flags);
int		ft_print_ptr(void *p, t_flag flags);
int		ft_print_unsigned(unsigned int n, t_flag flags);
int		ft_print_hex(unsigned int n, t_flag flags, char x);
void	print_pad(int pad, char c);

#endif
