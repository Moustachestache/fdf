/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:01:37 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:53:03 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_params	*ft_init_params(char *av[], t_vars *vars)
{
	t_params	*p;

	(void) vars;
	p = ft_calloc(1, sizeof(t_params));
	p->colour = 14606046;
	p->title = ft_strjoin("FDF: ", av[1]);
	p->valw = 1;
	p->valz = 1;
	p->valiso = 0.4;
	return (p);
}
