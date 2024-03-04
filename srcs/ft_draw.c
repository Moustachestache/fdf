/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:19:57 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 18:49:58 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_draw_octant_0(t_points pts, t_vars *vars)
{
	float	error;
	float	slope;

	pts.x0 = (pts.x0 * vars->params->valz);
	pts.x1 = (pts.x1 * vars->params->valz);
	pts.y0 = (pts.y0 * vars->params->valz);
	pts.y1 = (pts.y1 * vars->params->valz);
	error = 0.0;
	slope = (float)(pts.y1 - pts.y0) / (float)(pts.x1 - pts.x0);
	while (pts.x0 <= pts.x1)
	{
		img_pix_put(vars->img, pts.x0, pts.y0, pts.color);
		error += slope;
		if (error >= 0.5)
		{
			pts.y0++;
			error -= 1.0;
		}
		pts.x0++;
	}
}

static void	ft_draw_octant_1(t_points pts, t_vars *vars)
{
	float	error;
	float	slope;

	pts.x0 = (pts.x0 * vars->params->valz);
	pts.x1 = (pts.x1 * vars->params->valz);
	pts.y0 = (pts.y0 * vars->params->valz);
	pts.y1 = (pts.y1 * vars->params->valz);
	error = 0.0;
	slope = (float)(pts.x1 - pts.x0) / (float)(pts.y1 - pts.y0);
	while (pts.y0 <= pts.y1)
	{
		img_pix_put(vars->img, pts.x0, pts.y0, pts.color);
		error += slope;
		if (error >= 0.5)
		{
			pts.x0++;
			error -= 1.0;
		}
		pts.y0++;
	}
}

static void	ft_draw_octant_6(t_points pts, t_vars *vars)
{
	float	error;
	float	slope;

	pts.x0 = (pts.x0 * vars->params->valz);
	pts.x1 = (pts.x1 * vars->params->valz);
	pts.y0 = (pts.y0 * vars->params->valz);
	pts.y1 = (pts.y1 * vars->params->valz);
	error = 0.0;
	slope = (float)(pts.x1 - pts.x0) / (float)(pts.y0 - pts.y1);
	while (pts.y0 >= pts.y1)
	{
		img_pix_put(vars->img, pts.x0, pts.y0, pts.color);
		error += slope;
		if (error >= 0.5)
		{
			pts.x0++;
			error -= 1.0;
		}
		pts.y0--;
	}
}

static void	ft_draw_octant_7(t_points pts, t_vars *vars)
{
	float	error;
	float	slope;

	pts.x0 = (pts.x0 * vars->params->valz);
	pts.x1 = (pts.x1 * vars->params->valz);
	pts.y0 = (pts.y0 * vars->params->valz);
	pts.y1 = (pts.y1 * vars->params->valz);
	error = 0.0;
	slope = (float)(pts.y0 - pts.y1) / (float)(pts.x1 - pts.x0);
	while (pts.x0 <= pts.x1)
	{
		img_pix_put(vars->img, pts.x0, pts.y0, pts.color);
		error += slope;
		if (error >= 0.5)
		{
			pts.y0--;
			error -= 1.0;
		}
		pts.x0++;
	}
}

void	ft_drawline(t_points pts, t_vars *vars)
{
	int	temp;

	if (pts.color == 0)
		pts.color = INT_MAX;
	if (pts.x0 > pts.x1)
	{
		temp = pts.x1;
		pts.x1 = pts.x0;
		pts.x0 = temp;
		temp = pts.y1;
		pts.y1 = pts.y0;
		pts.y0 = temp;
	}
	if (pts.x0 < pts.x1 && pts.y0 <= pts.y1 
		&& (pts.x0 - pts.x1) <= (pts.y0 - pts.y1))
		ft_draw_octant_0(pts, vars);
	else if (pts.x0 <= pts.x1 && pts.y0 <= pts.y1 
		&& (pts.x0 - pts.x1) > (pts.y0 - pts.y1))
		ft_draw_octant_1(pts, vars);
	else if (pts.x0 < pts.x1 && pts.y0 >= pts.y1 
		&& (pts.x0 - pts.x1) > (pts.y1 - pts.y0))
		ft_draw_octant_6(pts, vars);
	else if (pts.x0 < pts.x1 && pts.y0 >= pts.y1 
		&& (pts.x0 - pts.x1) < (pts.y1 - pts.y0))
		ft_draw_octant_7(pts, vars);
}
