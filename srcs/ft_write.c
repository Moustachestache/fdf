/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:28:31 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:16:19 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_centered(t_vars *vars, int x, int y, char *text)
{
	int		i;
	char	**split;

	split = ft_split(text, '\n');
	i = 0;
	while (split[i])
	{
		mlx_string_put(vars->mlx, vars->win, x, y + (i * 26), \
		ft_hextoint("0xaaaaaa", vars), split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}
