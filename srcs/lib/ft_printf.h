/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:28:53 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/29 14:56:25 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//actual libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//test libraries
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_trigger(const char *s, va_list varlist);
int	ft_putstr(const char *s);
int	ft_putnbr(const int nb);
int	ft_putunsigned(const unsigned int nb);
int	ft_putchar(const int c);
int	ft_puthex(unsigned int hex, const char s);
int	ft_putpoint(unsigned long int i);
int	ft_skilki(unsigned long int i, int base);

#endif
