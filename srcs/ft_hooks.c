/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:05:32 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 19:47:18 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mouse_line(int x, int y, t_vars *vars)
{
	static int	x0;
	static int	y0;

	if (!x0 || !y0 || x0 < 0 || y0 < 0)
	{
		x0 = x;
		y0 = y;
	}
	else
	{
		ft_drawline(ft_setpts(x0, y0, x, y), vars);
		x0 = -1;
		y0 = -1;
	}
}

int	window_button(t_vars *vars)
{
	ft_exit(EXIT_SUCCESS, vars);
	return (69);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	if (keycode == 61)
	{
		vars->params->valw += 2;
		if (vars->params->valw > 100)
			vars->params->valw = 100;
	}
	if (keycode == 45)
	{
		vars->params->valw /= 2;
		if (vars->params->valw < 5)
			vars->params->valw = 5;
	}
	if (keycode == 65362)
		vars->params->yoffset += 100;
	if (keycode == 65364)
		vars->params->yoffset -= 100;
	if (keycode == 65363)
		vars->params->xoffset += 100;
	if (keycode == 65361)
		vars->params->xoffset -= 100;
	ft_drawfdf(vars);
	ft_konami(keycode, vars);
	return (keycode);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void) x;
	(void) y;
	(void) vars;
	if (!vars)
		return (1);
	return (button);
}
