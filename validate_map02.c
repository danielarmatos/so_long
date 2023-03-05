/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:57:15 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/02 20:33:13 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_row(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_column(char **map, int x, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][x] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_characters(t_map *map)
{
	ft_printf("\nExit: %i\nCollectibles: %i\n", map->exit, map->collectibles);
	ft_printf("Starting Pos: %i\n", map->starting_pos);
	if (map->exit > 1 || map->starting_pos > 1)
	{
		ft_printf("\nERROR: Map contains duplicated characters (exit/start)");
		return (0);
	}
	if (map->exit < 1 || map->starting_pos < 1)
	{
		ft_printf("\nERROR: No exit/start characters");
		return (0);
	}
	if (map->collectibles < 1)
	{
		ft_printf("\nERROR: No colectible characters");
		return (0);
	}
	ft_printf("\nCharacters are VALID!\n");
	return (1);
}

void	count_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == 'E')
				map->exit++;
			else if (map->map_array[i][j] == 'C')
				map->collectibles++;
			else if (map->map_array[i][j] == 'P')
				map->starting_pos++;
			j++;
		}
		i++;
	}
}

int	validate_map02(t_map *map)
{
	count_characters(map);
	if (check_characters(map) == 1)
	{
		if (check_row(map->map_array[0]) == 0)
			return (0);
		if (check_row(map->map_array[map->height - 1]) == 0)
			return (0);
		if (check_column(map->map_array, 0, map->height) == 0)
			return (0);
		if (check_column(map->map_array, (map->width - 1), map->height) == 0)
			return (0);
		ft_printf("\nWalls are VALID!\n");
		return (1);
	}
	return (0);
}
