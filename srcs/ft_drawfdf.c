/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawfdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:35:07 by mjochum           #+#    #+#             */
/*   Updated: 2023/09/19 17:36:39 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_points	ft_isometric(t_points pts, t_vars *vars)
{
	t_points	swap;

	swap = (t_points){
		((pts.x0 - pts.y0) * cos(vars->params->valiso)) * 2, 
		((pts.x0 + pts.y0) * sin(vars->params->valiso) - pts.z0) * 2, 
		pts.z0,
		((pts.x1 - pts.y1) * cos(vars->params->valiso)) * 2,
		((pts.x1 + pts.y1) * sin(vars->params->valiso) - pts.z1) * 2,
		pts.z1,
		pts.color};
	return (swap);
}

static t_points	ft_offset(t_points pts, t_vars *vars)
{
	int			xstart;
	int			ystart;
	t_points	swap;

	(void) vars;
	xstart = vars->params->xoffset + (WIN_WIDTH / 2);
	ystart = vars->params->yoffset + 69;
	swap = (t_points){
		xstart + pts.x0, ystart + pts.y0,
		pts.z0,
		xstart + pts.x1, ystart + pts.y1,
		pts.z1,
		pts.color};
	return (swap);
}

/*

	A ________ B
	 |        |
	 |        |
	 |        |
	 |________|
	D	   C

*/
static void	ft_drawnode(t_vars *vars, int x, int y)
{
	int			valw;
	int			color;
	t_points	pts;

	pts = (t_points){0};
	valw = vars->params->valw;
	if (x + 1 < vars->map->width)
	{
		color = vars->map->coord[y][x + 1].argb;
		pts = ft_isometric((t_points){(valw * x), (valw * y), \
			vars->map->coord[y][x].z, (valw * x) + valw, (valw * y), \
			vars->map->coord[y][x + 1].z, color}, vars);
		ft_drawline(ft_offset(pts, vars), vars);
	}
	if (y + 1 < vars->map->height)
	{
		color = vars->map->coord[y + 1][x].argb;
		pts = ft_isometric((t_points){(valw * x), (valw * y), \
			vars->map->coord[y][x].z, (valw * x), (valw * y) + valw, \
			vars->map->coord[y + 1][x].z, color}, vars);
		ft_drawline(ft_offset(pts, vars), vars);
	}
}

void static	ft_interface(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < PADDING)
	{
		ft_drawline((t_points){0, i, 0, \
			WIN_WIDTH, i, 0, \
			ft_hextoint("0xFFFFFF", vars)}, vars);
		ft_drawline((t_points){0, WIN_HEIGHT - i - 1, 0, \
			WIN_WIDTH, WIN_HEIGHT - i - 1, 0, \
			ft_hextoint("0xFFFFFF", vars)}, vars);
		ft_drawline((t_points){i, 0, 0, \
			i, WIN_HEIGHT, 0, \
			ft_hextoint("0xFFFFFF", vars)}, vars);
		ft_drawline((t_points){WIN_WIDTH - i - 1, 0, 0, \
			WIN_WIDTH - i - 1, WIN_HEIGHT, 0, \
			ft_hextoint("0xFFFFFF", vars)}, vars);
		i++;
	}
}

void	ft_drawfdf(t_vars *vars)
{
	int	x;
	int	y;

	ft_create_image(vars);
	x = 0;
	y = 0;
	while (x < vars->map->width)
	{
		while (y < vars->map->height)
		{
			ft_drawnode(vars, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	ft_interface(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	ft_centered(vars, PADDING + 5, PADDING + 25, \
		"zoom:[+] [-]\nmove: [arrows]\nkonami: [code]");
}
