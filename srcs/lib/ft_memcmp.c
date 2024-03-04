/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:05:20 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/06 15:45:37 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*pts1;
	unsigned char		*pts2;

	i = 0;
	pts1 = (unsigned char *) s1;
	pts2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (pts1[i] != pts2[i])
			return (pts1[i] - pts2[i]);
		i++;
	}
	return (0);
}
