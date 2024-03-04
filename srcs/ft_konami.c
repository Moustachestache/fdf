/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_konami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:49:31 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/06 19:50:23 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_check_sequence(int keycode, int prev, int old, int count)
{
	(void) old;
	(void) prev;
	if ((count == 1 || count == 2) && (keycode == 65362))
		return (1);
	else if ((count == 3 || count == 4) && (keycode == 65364))
		return (1);
	else if ((count == 5 || count == 7) && (keycode == 65361))
		return (1);
	else if ((count == 6 || count == 8) && (keycode == 65363))
		return (1);
	else if (count == 9 && keycode == 97)
		return (1);
	else if (count == 10 && keycode == 98)
		return (1);
	return (0);
}

static int	ft_check_konami(int keycode)
{
	if ((keycode >= 65361 && keycode <= 65364) || \
		(keycode == 97) || (keycode == 98))
		return (1);
	return (0);
}

void	ft_konami(int keycode, t_vars *vars)
{
	static int	prev;
	static int	old;
	static int	count;

	if (ft_check_konami(keycode) == 0 || \
	ft_check_sequence(keycode, prev, old, count) == 0)
	{
		prev = 0;
		old = 0;
		count = 0;
	}
	else if (count > 9)
		ft_meluche(vars);
	count++;
	old = prev;
	prev = keycode;
}
