/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:17:49 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 12:16:18 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_exit(int exit_value, t_vars *vars)
{
	if (exit_value == EXIT_FAILURE)
		ft_printf("oh no. ");
	ft_printf("exiting program with exit value %i.\n", exit_value);
	ft_free_all(vars, 1);
	ft_free_all(vars, 3);
	if (vars->img.mlx_img)
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	if (vars->win)
		mlx_clear_window(vars->mlx, vars->win);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	ft_free_all(vars, 2);
	exit(exit_value);
}
