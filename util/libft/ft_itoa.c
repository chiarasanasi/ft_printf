/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:41:14 by csanasi           #+#    #+#             */
/*   Updated: 2026/05/23 17:47:18 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_fill_res(char *res, long ln, int i)
{
	while (i > 0)
	{
		i--;
		res[i] = (ln % 10) + '0';
		ln = ln / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		is_neg;
	long	ln;

	is_neg = 0;
	ln = n;
	if (ln < 0)
	{
		is_neg = 1;
		ln = -ln;
	}
	i = ft_n_len(ln) + is_neg;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	ft_fill_res(res, ln, i);
	if (is_neg)
		res[0] = '-';
	return (res);
}
