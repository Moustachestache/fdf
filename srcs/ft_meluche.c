/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meluche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:24:06 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:16:46 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_putstars(t_vars *vars, int density)
{
	int	i;
	int	j;

	if (density > 50)
		density = 50;
	i = 0;
	j = 0;
	while (i < density)
	{
		while (j < density)
		{
			mlx_string_put(vars->mlx, vars->win, rand() % WIN_WIDTH, \
				rand() % WIN_HEIGHT, ft_hextoint("0x333333", vars), "*");
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_meluche(t_vars *vars)
{
	(void) vars;
}
