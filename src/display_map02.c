/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:41:26 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/14 18:35:13 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_obstacle(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->obstacle, (x * data->px), (y * data->px));
}

void	display_collectible(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->collectible, (x * data->px), (y * data->px));
}

void	display_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->player01, (x * data->px), (y * data->px));
	data->map->curr_pos_x = x;
	data->map->curr_pos_y = y;
}

void	display_bg(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->bg, (x * data->px), (y * data->px));
}

void	display_content(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < (data->map->height - 1))
	{
		j = 1;
		while (j < (data->map->width - 1))
		{
			if (data->map->map_array[i][j] == '0')
				display_bg(data, j, i);
			if (data->map->map_array[i][j] == 'P')
				display_player(data, j, i);
			if (data->map->map_array[i][j] == 'C')
				display_collectible(data, j, i);
			if (data->map->map_array[i][j] == '1')
				display_obstacle(data, j, i);
			if (data->map->map_array[i][j] == 'E')
				display_exit(data, j, i);
			j++;
		}
		i++;
	}
}
