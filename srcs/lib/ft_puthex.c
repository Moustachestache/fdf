/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:41:03 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/30 15:58:45 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhex(unsigned int hex, const char s)
{
	if (hex >= 16)
	{
		ft_printhex(hex / 16, s);
	}
	if (s == 'x')
		return (write(1, &"0123456789abcdef"[hex % 16], 1));
	else if (s == 'X')
		return (write(1, &"0123456789ABCDEF"[hex % 16], 1));
	return (0);
}

int	ft_skilki(unsigned long int i, int base)
{
	int	j;

	j = 0;
	while (i > 0)
	{
		i /= base;
		j++;
	}
	if (j == 0)
		return (1);
	return (j);
}

int	ft_puthex(unsigned int hex, const char s)
{
	ft_printhex(hex, s);
	return (ft_skilki(hex, 16));
}
