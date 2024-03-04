/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:23:22 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/14 13:09:37 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	unsigned char		*b;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char str[100] = "une chaine de texte qui existe et qui est la";
	char str1[100] = "re une chaine de cacaracteres";
	char str2[420] = "";
	char str3[420] = "";

	printf("strs: \n str0:%s\n str1:%s\n 
str2:%s\n str3:%s\n", str, str1, str2, str3);
	printf("memcpy: %p\n", ft_memcpy(str2, str1, 10));
	printf("memcpy: %p\n", memcpy(str3, str1, 15));
	printf("strs: \n str0:%s\n str1:%s\n str2:%s\n 
str3:%s\n", str, str1, str2, str3);
}*/
