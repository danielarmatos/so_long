/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:25 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/14 18:30:40 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_walls(t_data *data)
{
	int	i;

	i = 1;
	while (i < (data->map->width - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map->sprites->wall_h, (i * data->px), 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->wall_h,
			(i * data->px), ((data->map->height - 1) * data->px));
		i++;
	}
	i = 1;
	while (i < (data->map->height - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map->sprites->wall_p, 0, (i * data->px));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->wall_p,
			((data->map->width - 1) * data->px), (i * data->px));
		i++;
	}
}

void	display_corners(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->map->sprites->corner_tl, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->corner_tr, ((data->map->width - 1) * data->px), 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->corner_bl, 0, ((data->map->height - 1) * data->px));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->corner_br, ((data->map->width - 1) * data->px),
		((data->map->height - 1) * data->px));
}

void	display_map(t_data *data)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	data->map->sprites = sprites;
	setup_sprites(data);
	display_corners(data);
	display_walls(data);
	display_content(data);
}
