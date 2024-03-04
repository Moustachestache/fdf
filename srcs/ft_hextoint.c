/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:14:05 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:30:32 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_ishex(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (c);
	return (0);
}

static int	*init_hex_table(void)
{
	int	*hex;

	hex = ft_calloc(256, sizeof(int));
	hex['0'] = 0;
	hex['1'] = 1;
	hex['2'] = 2;
	hex['3'] = 3;
	hex['4'] = 4;
	hex['5'] = 5;
	hex['6'] = 6;
	hex['7'] = 7;
	hex['8'] = 8;
	hex['9'] = 9;
	hex['a'] = 10;
	hex['b'] = 11;
	hex['c'] = 12;
	hex['d'] = 13;
	hex['e'] = 14;
	hex['f'] = 15;
	return (hex);
}

int	ft_hextoint(char *str, t_vars *vars)
{
	int	n;
	int	i;

	if (!vars->params->hex)
		vars->params->hex = init_hex_table();
	i = 0;
	n = 0;
	if (str[0] == '0' && str[1] == 'x')
		i = 2;
	while (str[i] && ft_ishex(str[i]) > 0 && i < 8)
	{
		n += vars->params->hex[0 + ft_tolower(str[i])];
		if (i < 7)
			n <<= 4;
		i++;
	}
	return (n);
}
