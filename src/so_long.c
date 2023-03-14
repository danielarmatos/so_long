/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:40:17 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/02/11 13:30:20 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->starting_pos = 0;
	map->exit = 0;
	map->image_size = 50;
	map->curr_pos_x = 0;
	map->curr_pos_y = 0;
	map->collected_col = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;
	
	map = malloc(sizeof(t_map));
	if (argc == 2)
	{
		setup_map(map);
		if (validate_map(argv[1], map) == 0)
		{
			ft_printf("\n\nMap is INVALID!\n");
			return (0);
		}
		else
		{
			ft_printf("\nMap is VALID!\n");
			render_map(map);
		}
			
	}
}