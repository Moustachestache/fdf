/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:09:43 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:15:56 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

static void	ft_setnode(char *buffer, t_node *node, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		while (buffer[i] == ' ')
			i++;
		node[j].z = ft_atoi(buffer + i);
		while (ft_isalnum(buffer[i]) || buffer[i] == '-')
			i++;
		if (buffer[i] && buffer[i] == ',' && buffer[i++])
		{
			node[j].argb = ft_hextoint(buffer + i, vars);
			while (ft_isalnum(buffer[i]))
				i++;
		}
		else
			node[j].argb = 0;
		j++;
	}
}

static void	ft_addline_cont(char *buffer, t_map *map, t_vars *vars)
{
	int		i;
	t_node	**swap;
	t_node	**temp;

	i = 0;
	swap = (t_node **)ft_calloc(map->height + 1, sizeof(t_node *));
	while (i < map->height && map->coord[i])
	{
		swap[i] = map->coord[i];
		i++;
	}
	swap[i] = (t_node *)ft_calloc(map->width, sizeof(t_node));
	ft_setnode(buffer, swap[i], vars);
	map->height++;
	temp = map->coord;
	map->coord = swap;
	free(temp);
}

static void	ft_addline(char *buffer, t_map *map, t_vars *vars)
{
	int		i;

	i = 0;
	if (!map->height)
	{
		map->height = 1;
		map->coord[0] = (t_node *)ft_calloc(map->width, sizeof(t_node));
		ft_setnode(buffer, map->coord[0], vars);
		i++;
	}
	else
		ft_addline_cont(buffer, map, vars);
}

void	ft_getmap(t_map *map, t_vars *vars)
{
	char	*buffer;

	buffer = get_next_line(map->fd);
	if (buffer == NULL)
		ft_exit(EXIT_FAILURE, vars);
	if (!map->coord)
	{
		map->width = ft_countnodes(buffer, ' ');
		map->coord = (t_node **)ft_calloc(1, sizeof(t_node *));
		if (!map->coord)
			ft_exit(EXIT_FAILURE, vars);
	}
	while (buffer)
	{
		ft_addline(buffer, map, vars);
		free(buffer);
		buffer = get_next_line(map->fd);
	}
	if (buffer)
		free(buffer);
}

t_map	*ft_init_map(char *av[], t_vars *vars)
{
	t_map	*map;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit(EXIT_FAILURE, vars);
	map->fd = open(av[1], O_RDONLY);
	if (map->fd == -1 || read(map->fd, NULL, 0) == -1 
		|| !ft_filext(av[1], ".fdf"))
		ft_exit(EXIT_FAILURE, vars);
	map->mapname = av[1];
	return (map);
}
