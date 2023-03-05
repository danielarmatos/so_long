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

char	move_player_up(t_data *data)
{
	int	x;
	int	y;
	int	a;

	x = data->map->curr_pos_x;
	y = data->map->curr_pos_y;
	a = data->map->map_array[y - 1][x];
	if (data->map->map_array[y - 1][x] != '1')
	{
		data->map->map_array[y][x] = '0';
		if (data->map->map_array[y - 1][x] != 'E')
			data->map->map_array[y - 1][x] = 'P';
		data->map->curr_pos_y = y - 1;
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.bg, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.player01, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, ((x) * data->px), ((y - 1) * data->px));
	}
	return (a);
}

char	move_player_down(t_data *data)
{
	int	x;
	int	y;
	int	a;

	x = data->map->curr_pos_x;
	y = data->map->curr_pos_y;
	a = data->map->map_array[y + 1][x];
	if (data->map->map_array[y + 1][x] != '1')
	{
		data->map->map_array[y][x] = '0';
		if (data->map->map_array[y + 1][x] != 'E')
			data->map->map_array[y + 1][x] = 'P';
		data->map->curr_pos_y = y + 1;
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.bg, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.player01, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, ((x) * data->px), ((y + 1) * data->px));
	}
	return (a);
}

char	move_player_left(t_data *data)
{
	int	x;
	int	y;
	int	a;

	x = data->map->curr_pos_x;
	y = data->map->curr_pos_y;
	a = data->map->map_array[y][x - 1];
	if (data->map->map_array[y][x - 1] != '1')
	{
		data->map->map_array[y][x] = '0';
		if (data->map->map_array[y][x - 1] != 'E')
			data->map->map_array[y][x - 1] = 'P';
		data->map->curr_pos_x = x - 1;
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.bg, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.player01, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, ((x - 1) * data->px), ((y) * data->px));
	}
	return (a);
}
char	move_player_right(t_data *data)
{
	int	x;
	int	y;
	int	a;

	x = data->map->curr_pos_x;
	y = data->map->curr_pos_y;
	a = data->map->map_array[y][x + 1];
	if (data->map->map_array[y][x + 1] != '1')
	{
		data->map->map_array[y][x] = '0';
		if (data->map->map_array[y][x + 1] != 'E')
			data->map->map_array[y][x + 1] = 'P';
		data->map->curr_pos_x = x + 1;
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.bg, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, (x * data->px), (y * data->px));
		data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->map->graphic.player01, &data->px, &data->px);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, ((x + 1) * data->px), ((y) * data->px));
	}
	return (a);
}

int	key_hook(int key, t_data *data)
{
	char	a;

	if ((key == 119 || key == 65362))
		a = move_player_up(data);
	if ((key == 115 || key == 65364))
		a = move_player_down(data);
	if ((key == 100 || key == 65363))
		a = move_player_right(data);
	if ((key == 97 || key == 65361))
		a = move_player_left(data);
	ft_printf("\n%c\n", a);
	if (a == 'C')
	{
		data->map->collected_col++;
		if (data->map->collected_col == data->map->collectibles)
			ft_printf("\nAll collectibles collected!!!!\n");
	}
	if (a == 'E')
	{
		if (data->map->collected_col == data->map->collectibles)
			ft_printf("\nFinished game successfully\n");
	}
	return (0);
}
