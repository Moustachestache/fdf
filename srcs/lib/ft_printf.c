/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:48:45 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/30 18:41:13 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// va_start	= initialize struct to be used by va-arg & va-end
// va_arg	= gets next arg. Must specify type
// va_copy	= frick knows
// va_end	= close
int	ft_printf(const char *s, ...)
{
	va_list	varlist;
	size_t	i;
	size_t	len;

	va_start(varlist, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
			len += write(1, &s[i], 1);
		else if (s[i] == '%' && s[i + 1] != '\0')
		{
			len += ft_trigger(&s[i + 1], varlist);
			i++;
		}
		i++;
	}
	va_end(varlist);
	return (len);
}

int	ft_trigger(const char *s, va_list varlist)
{
	if (*s == 's')
		return (ft_putstr(va_arg(varlist, char *)));
	else if (*s == 'i' || *s == 'd')
		return (ft_putnbr(va_arg(varlist, int)));
	else if (*s == 'c')
		return (ft_putchar(va_arg(varlist, int)));
	else if (*s == 'x' || *s == 'X')
		return (ft_puthex(va_arg(varlist, unsigned int), *s));
	else if (*s == 'p')
		return (ft_putpoint(va_arg(varlist, unsigned long int)));
	else if (*s == 'u')
		return (ft_putunsigned(va_arg(varlist, unsigned int)));
	else if (*s == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
