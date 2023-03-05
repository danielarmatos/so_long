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
/*
void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	ft_printf("\n");
	while(map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}*/

t_info	check_path(char **map, t_info *map_info, int x, int y)
{	
//	print_map(map);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (*map_info);
	if (map[y][x] == 'C')
		map_info->collectibles += 1;
	if (map[y][x] == 'E')
		map_info->exit += 1;
	map[y][x] = 'X';
	check_path(map, map_info, (x + 1), y);
	check_path(map, map_info, (x - 1), y);
	check_path(map, map_info, x, (y + 1));
	check_path(map, map_info, x, (y - 1));
	return (*map_info);
}

t_point	get_start_pos(char **map, int height, int width)
{
	int		x;
	int		y;
	t_point	start_pos;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	start_pos.x = x;
	start_pos.y = y;
	return (start_pos);
}

t_info	validate_path(char **map, int height, int width)
{
	t_point	start_pos;
	t_info	map_info;

	start_pos = get_start_pos(map, height, width);
	ft_printf("\nPos is: %i, %i", start_pos.x, start_pos.y);
	map_info.width = width;
	map_info.height = height;
	map_info.collectibles = 0;
	map_info.exit = 0;
	map_info = check_path(map, &map_info, start_pos.x, start_pos.y);
	ft_printf("\n\n=====\n\n%i %i", map_info.collectibles, map_info.exit);
	return (map_info);
}
