/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csanasi <csanasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:41:14 by csanasi           #+#    #+#             */
/*   Updated: 2026/06/02 18:11:53 by csanasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_n_len(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char				*res;
	unsigned int		len;

	len = ft_n_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
