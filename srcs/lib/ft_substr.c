/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:09:48 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/08 13:43:00 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// feat gbricot pour le "actual_len"
// check:
//	1. S exist & non empty
//	2. len non 0
//	3. index start not superior to length of s
//	4. check actual length because maybe len is way big
//	5. calloc works
// return str;
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	actual_len;
	char	*str;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) < start)
		return (ft_calloc(1, sizeof (char)));
	actual_len = ft_strlen(s + start);
	if (actual_len + 1 < len)
		len = actual_len;
	str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char str[] = "pipi poupou, sa mere et re pipi";
	printf("%s\n", ft_substr(str, 5, 10));
	return (0);
}*/
