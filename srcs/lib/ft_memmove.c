/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:06:47 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/14 13:09:22 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*adest;
	unsigned char	*asrc;

	adest = (unsigned char *)dest;
	asrc = (unsigned char *)src;
	i = 0;
	if (asrc > adest)
		ft_memcpy(adest, asrc, n);
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			adest[i] = asrc[i];
			i--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char str1[100] = "coucou les loulous jai le slip plein de didou";
	char str2[100] = "rien";
	char str3[100] = "rien";
	
	printf("str1:%s\nstr2:%s\nft result:%p\nog result:
%p",str1,str2,ft_memmove(str2, str1, 20), memmove(str3,str1,20));
}*/
