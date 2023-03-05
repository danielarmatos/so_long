/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:41:26 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/03 20:57:10 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_obstacle(t_data *data, int x, int y)
{
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.obstacle, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
}

void	display_collectible(t_data *data, int x, int y)
{
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.collectible, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
}

void	display_player(t_data *data, int x, int y)
{
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.player01, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
	data->map->curr_pos_x = x;
	data->map->curr_pos_y = y;
}

void	display_bg(t_data *data, int x, int y)
{
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.bg, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
}

void	display_content(t_data *data)
{
	int	i;
	int j;

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
			j++;
		}
		i++;
	}
}
