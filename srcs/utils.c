/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:56:29 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 19:19:25 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_ishexa(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 8)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || \
		(str[i] >= 'a' && str[i] <= 'f') || \
		(str[i] >= 'A' && str[i] <= 'F') || (str[i] == 'x')))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c > 0 && c < 33)
		return (1);
	return (0);
}

int	ft_lentochar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_filext(char *str, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(ext);
	while (str[i] == ext[j] && i >= 0 && j >= 0)
	{
		if (j == 0)
			return (1);
		i--;
		j--;
	}
	return (0);
}
