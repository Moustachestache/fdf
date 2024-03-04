/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:41:13 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/30 18:38:56 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr(int nb)
{
	if (nb > 9)
	{
		ft_printnbr(nb / 10);
	}
	return (write(1, &"0123456789"[nb % 10], 1));
}

int	ft_putnbr(int nb)
{
	int	i;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	i = 0;
	if (nb < 0)
	{
		i = write(1, "-", 1);
		nb *= -1;
	}
	ft_printnbr(nb);
	return (ft_skilki(nb, 10) + i);
}

static int	ft_printunsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_printunsigned (nb / 10);
	}
	return (write(1, &"0123456789"[nb % 10], 1));
}

int	ft_putunsigned(unsigned int nb)
{
	int	i;

	i = 0;
	ft_printunsigned(nb);
	return (ft_skilki(nb, 10) + i);
}
