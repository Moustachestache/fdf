/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:09 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:17 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	int		i;

	i = 0;
	r = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (r == NULL)
		return (NULL);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
