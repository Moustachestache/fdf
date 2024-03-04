/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:57:56 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 18:43:07 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_display(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_set_font(vars->mlx, vars->win, \
		"-sony-fixed-medium-r-normal--24-230-75-75-c-120-iso8859-1");
	ft_drawfdf(vars);
	mlx_loop(vars->mlx);
}
