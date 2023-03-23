/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:59:24 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/14 19:59:27 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_sprite_anim(t_data *data)
{
	static int	i;
	int			x;
	int			y;

	x = data->map->exit_pos_x;
	y = data->map->exit_pos_y;
	if (!i)
		i = 1;
	if (i == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->exit01, (x * data->px), (y * data->px));
	}
	if (i == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->exit02, (x * data->px), (y * data->px));
	}
	if (i == 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->exit03, (x * data->px), (y * data->px));
		i = 0;
	}
	i++;
}

void	display_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map->sprites->exit, (x * data->px), (y * data->px));
	data->map->exit_pos_x = x;
	data->map->exit_pos_y = y;
}
