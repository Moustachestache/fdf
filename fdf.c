/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:44 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 14:28:12 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vars	*ft_init(char *av[])
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		ft_exit(EXIT_FAILURE, vars);
	vars->mlx = mlx_init();
	vars->params = ft_init_params(av, vars);
	vars->map = ft_init_map(av, vars);
	vars->win = mlx_new_window(vars->mlx, \
		WIN_WIDTH, WIN_HEIGHT, vars->params->title);
	ft_getmap(vars->map, vars);
	if (vars->map->height > vars->map->width)
		vars->params->valw += (((WIN_HEIGHT / vars->map->height) - 1) / 2);
	else
		vars->params->valw += (((WIN_WIDTH / vars->map->width) - 1) / 2);
	ft_create_image(vars);
	return (vars);
}

int	main(int ac, char *av[])
{
	t_vars	*vars;

	if (ac != 2)
		return (ft_printf("usage: %s [PATH_TO_MAP]", av[0]));
	if (!ft_filext(av[1], ".fdf"))
		return (ft_printf("file must be in .fdf format\n"));
	if (read(open(av[1], O_RDONLY), NULL, 0))
		return (ft_printf("file doesn't exist\n"));
	vars = ft_init(av);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, window_button, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	ft_display(vars); 
}
