/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:41:29 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/30 18:27:02 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

static int	ft_printhexlong(unsigned long int hex, const char s)
{
	if (hex >= 16)
	{
		ft_printhexlong(hex / 16, s);
	}
	if (s == 'x')
		return (write(1, &"0123456789abcdef"[hex % 16], 1));
	else if (s == 'X')
		return (write(1, &"0123456789ABCDEF"[hex % 16], 1));
	return (0);
}

static int	ft_puthexlong(unsigned long int hex, const char s)
{
	ft_printhexlong(hex, s);
	return (ft_skilki(hex, 16));
}

int	ft_putpoint(unsigned long int i)
{
	int	j;

	j = 0;
	if (i > 0)
	{
		write(1, "0x", 2);
		j = 2;
		ft_puthexlong(i, 'x');
	}
	else
	{
		return (write(1, "(nil)", 5));
	}
	return (ft_skilki(i, 16) + j);
}
