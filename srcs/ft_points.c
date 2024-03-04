/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:59:00 by mjochum           #+#    #+#             */
/*   Updated: 2023/07/02 17:01:02 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_points	ft_setpts(int x0, int y0, int x1, int y1)
{
	t_points	points;

	points.x0 = x0;
	points.y0 = y0;
	points.x1 = x1;
	points.y1 = y1;
	return (points);
}
