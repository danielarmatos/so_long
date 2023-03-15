/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:13:34 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/02/16 16:45:01 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_map *map, int x, int y)
{	
	if (map->map_array_val[y][x] == '1' || map->map_array_val[y][x] == 'X')
		return (1);
	if (map->map_array_val[y][x] == 'C')
		map->validation_col += 1;
	if (map->map_array_val[y][x] == 'E')
		map->validation_exit += 1;
	map->map_array_val[y][x] = 'X';
	check_path(map, (x + 1), y);
	check_path(map, (x - 1), y);
	check_path(map, x, (y + 1));
	check_path(map, x, (y - 1));
	return (1);
}

t_point	get_start_pos(t_map *map)
{
	int		x;
	int		y;
	t_point	start_pos;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_array[y][x] == 'P')
				break ;
			x++;
		}
		if (map->map_array[y][x] == 'P')
			break ;
		y++;
	}
	start_pos.x = x;
	start_pos.y = y;
	return (start_pos);
}

int	validate_path(t_map *map)
{
	t_point	start_pos;

	start_pos = get_start_pos(map);
	map->validation_col = 0;
	map->validation_exit = 0;
	check_path(map, start_pos.x, start_pos.y);
	if (map->validation_exit == 1 && map->validation_col == map->collectibles)
	{
		ft_printf("\nMap path is VALID!");
		return (1);
	}
	ft_printf("\nError: Map path is not valid!");
	return (0);
}
