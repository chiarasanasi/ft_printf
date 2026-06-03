/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:41:14 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:10:58 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_n_len_hex(unsigned long n)
{
	unsigned long	len;

	len = 1;
	while (n > 15)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

char	*ft_ultoa_hex(unsigned long n, char *base)
{
	char				*res;
	unsigned long		len;

	len = ft_n_len_hex(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = base[n % 16];
		n = n / 16;
	}
	return (res);
}
