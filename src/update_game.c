/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:44:43 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/04 19:09:12 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	move_player(t_data *data, int x2, int y2)
{
	int	x;
	int	y;
	char	c;
	int	move;

	x = data->map->curr_pos_x;
	y = data->map->curr_pos_y;
	c = data->map->map_array[y2][x2];
	move = 1;
	if (c == '1')
		move = 0;
	if (c == 'E')
		if (data->map->collected_col != data->map->collectibles)
			move = 0;
	if (move == 1)
	{
		data->map->map_array[y][x] = '0';
		if (data->map->map_array[y2][x2] != 'E')
			data->map->map_array[y2][x2] = 'P';
		data->map->curr_pos_x = x2;
		data->map->curr_pos_y = y2;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->bg, (x * data->px), (y * data->px));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->map->sprites->player01,
			(x2 * data->px), (y2 * data->px));
	}
	return (c);
}

char	check_move(int key, t_data *data)
{
	char	c;

	if ((key == 119 || key == 65362))
		c = move_player(data, data->map->curr_pos_x,
				(data->map->curr_pos_y - 1));
	if ((key == 115 || key == 65364))
		c = move_player(data, data->map->curr_pos_x,
				(data->map->curr_pos_y + 1));
	if ((key == 100 || key == 65363))
		c = move_player(data, (data->map->curr_pos_x + 1),
				data->map->curr_pos_y);
	if ((key == 97 || key == 65361))
		c = move_player(data, (data->map->curr_pos_x - 1),
				data->map->curr_pos_y);
	return (c);
}

int	key_hook(int key, t_data *data)
{
	char	c;
	c = check_move(key, data);
	
	if (c == 'C')
	{
		data->map->collected_col++;
		if (data->map->collected_col == data->map->collectibles)
			ft_printf("\nAll collectibles collected!!!!\n");
	}
	if (c == 'E')
	{
		if (data->map->collected_col == data->map->collectibles)
			ft_printf("\nFinished game successfully\n");
	}
	return (0);
}

