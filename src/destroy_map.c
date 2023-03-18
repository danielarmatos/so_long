/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:53:02 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/04 16:04:32 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit (0);
	return (0);
}

void	destroy_map_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free (map->map_array[i]);
		free (map->map_array_val[i]);
		i++;
	}
}

void	destroy_map(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->player01);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->obstacle);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->corner_tl);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->corner_bl);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->corner_tr);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->corner_br);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->wall_h);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->wall_p);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->bg);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->collectible);
	mlx_destroy_image(data->mlx_ptr, data->map->sprites->exit);
	destroy_map_array(data->map);
}
