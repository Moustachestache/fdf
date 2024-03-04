/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:18:38 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 19:48:32 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pix_put(t_image img, int x, int y, int color)
{
	int	i;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	i = (x * img.bpp / 8) + (y * img.line_len);
	img.addr[i] = color;
	img.addr[++i] = color >> 8;
	img.addr[++i] = color >> 16;
}

void	ft_create_image(t_vars *vars)
{
	if (vars->img.addr)
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	vars->img.mlx_img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, \
			&vars->img.bpp, &vars->img.line_len, \
			&vars->img.endian);
}
