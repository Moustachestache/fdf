/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:25:00 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 19:14:28 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
// move to next node
// return NULL if at end (no more node or \n")
char	*ft_nextnode(char *buffer, char nodeid)
{
	(void) buffer;
	(void) nodeid;
//	go through buffer, pick out things one by one.

	int	i;
	char	*swap;

	i = 0;
	swap = NULL;
ft_printf("[%s]", buffer);
	while (buffer[i] && buffer[i] != nodeid)
		i++;
	i++;
	if (buffer[i] && buffer[i] != '\n')
		swap = ft_strdup(buffer + i);
	ft_printf("[%s]\n", swap);
	free(buffer);
	return (swap);
}*/

// counts node
int	ft_countnodes(char *str, char nodeid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == nodeid && i >= 1)
		{
			j++;
			while (str[i] == nodeid)
				i++;
		}
		i++;
	}
	if (j > 0)
		return (j + 1);
	else
		return (j);
}
/*
// hexnode of size 9
int	ft_gethex(char *buffer, int hexnode)
{
	hexnode = ft_hextoint(buffer);
}*/
