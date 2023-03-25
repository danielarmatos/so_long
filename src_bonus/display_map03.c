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

void	display_collectible_sprite(t_data *data, int x, int y, int j, int i)
{
	//static int	i;

	//if (!i)
	//	i = 1;
	//ft_printf("%i, %i\n", j, i);
	if (i == 1)
	{
		if (j == 0)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible, (x * data->px), (y * data->px));
			ft_printf("=== %i, %i\n", j, i);
		}
		if (j == 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible01_02, (x * data->px), (y * data->px));
			ft_printf("=== %i, %i\n", j, i);
		}
		if (j == 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible01_03, (x * data->px), (y * data->px));
			ft_printf("=== %i, %i\n", j, i);
		}
	}
	if (i == 2)
	{
		if (j == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible02, (x * data->px), (y * data->px));
		if (j == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible02_02, (x * data->px), (y * data->px));
		if (j == 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible02_03, (x * data->px), (y * data->px));
	}
	if (i == 2)
	{
		if (j == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible03, (x * data->px), (y * data->px));
		if (j == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible03_02, (x * data->px), (y * data->px));
		if (j == 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible03_03, (x * data->px), (y * data->px));
	}
	if (i == 4)
	{
		if (j == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible04, (x * data->px), (y * data->px));
		if (j == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible04_02, (x * data->px), (y * data->px));
		if (j == 2)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->map->sprites->collectible04_03, (x * data->px), (y * data->px));
		//i = 0;
	}
	//i++;
}

void	collectible_sprite_anim(t_data *data)
{
	static int	j;
	int			i;
	int			x;
	int			y;

	if (!j)
		j = 0;
	i = 1;
	y = 1;
	while (y < (data->map->height - 1))
	{
		x = 1;
		while (x < (data->map->width - 1))
		{
			if (data->map->map_array[y][x] == 'C')
			{
				display_collectible_sprite(data, x, y, j, i);
				j++;
				i++;
				if (j == 4)
					j = 0;
				if (i == 5)
					i = 0;
			}
			x++;
		}
		y++;
	}

}

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
