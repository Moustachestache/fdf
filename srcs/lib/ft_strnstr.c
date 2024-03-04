/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:09:12 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/14 13:29:08 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;

	if (big == NULL && len == 0)
		return (NULL);
	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char *)big);
	while (*big && len-- >= lenlittle)
	{
		if (*big == *little && ft_strncmp(big, little, lenlittle) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char str1[1000] = "la vie en slip, le slop en vie.";
	char str2[1000] = "le slop";

	printf("str1:%s\nstr2:%s\nstrnstr:
%s", str1, str2, ft_strnstr(str1, str2, 1000));
}*/
