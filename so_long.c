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

void	setup_graphic(t_map *map)
{
	map->graphic.player01 = "./images/player01.xpm";
	map->graphic.obstacle = "./images/obstacle01.xpm";
	map->graphic.corner_tl = "./images/corner_tl.xpm";
	map->graphic.corner_bl = "./images/corner_bl.xpm";
	map->graphic.corner_tr = "./images/corner_tr.xpm";
	map->graphic.corner_br = "./images/corner_br.xpm";
	map->graphic.wall_h = "./images/wall_h.xpm";
	map->graphic.wall_p = "./images/wall_p.xpm";
	map->graphic.bg = "./images/background.xpm";
	map->graphic.collectible = "./images/collectible.xpm";
}

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
	setup_graphic(map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc == 2)
	{
		setup_map(&map);
		if (validate_map(argv[1], &map) == 0)
		{
			ft_printf("\n\nMap is INVALID!\n");
			return (0);
		}
		else
		{
			ft_printf("\nMap is VALID!\n");
			render_map(&map);
		}
			
	}
}
