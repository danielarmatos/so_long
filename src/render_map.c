/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:31:02 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/14 18:33:04 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	return (0);
}

int	init_render_map(t_map *map, t_data *data)
{
	data->map = map;
	data->px = 52;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (map->width * data->px),
			(map->height * data->px), "Dani's So Long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr,
			(map->width * data->px), (map->height * data->px));
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (1);
}

int	render_map(t_map *map)
{
	t_data	*data;
	int		result;

	data = malloc(sizeof(t_data));
	result = init_render_map(map, data);
	if (result == 0)
		return (0);
	display_map (data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify,
		StructureNotifyMask, &close_window, data);
	mlx_key_hook(data->win_ptr, &key_hook, data);
	mlx_loop(data->mlx_ptr);
	ft_printf("Destroy map\n");
	destroy_map(data);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map->map_array);
	free(data->map->map_array_val);
	free(data->map->sprites);
	free(data->map);
	free(data->mlx_ptr);
	free(data);
	return (1);
}
