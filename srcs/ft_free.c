/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:24:33 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:26:01 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->coord[i])
			free(map->coord[i]);
		i++;
	}
	if (map->coord)
		free(map->coord);
}

static void	ft_free_params(t_params *params)
{
	if (params->title)
		free(params->title);
	if (params->hex)
		free(params->hex);
}

static void	ft_free_vars(t_vars *vars)
{
	if (vars->params)
		free(vars->params);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->map)
		free(vars->map);
	if (vars)
		free(vars);
}

void	ft_free_all(t_vars *vars, int code)
{
	if (code == 1)
		ft_free_map(vars->map);
	else if (code == 2)
		ft_free_vars(vars);
	else if (code == 3)
		ft_free_params(vars->params);
	else
		return ;
}
