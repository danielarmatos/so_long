/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:25 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/03 20:39:26 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_sprites(t_data *data)
{
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.player01, &data->px, &data->px);
}

void	display_walls(t_data *data)
{
	int	i;

	i = 1;
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.wall_h, &data->px, &data->px);
	while (i < (data->map->width - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, (i * data->px), 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
			(i * data->px), ((data->map->height - 1) * data->px));
		i++;
	}
	i = 1;
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.wall_p, &data->px, &data->px);
	while (i < (data->map->height - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.mlx_img, 0, (i * data->px));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
			((data->map->width - 1) * data->px), (i * data->px));
		i++;
	}
}

void	display_corners(t_data *data)
{
	//ft_printf("ola\n");
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.corner_tl, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.corner_tr, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, ((data->map->width - 1) * data->px), 0);
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.corner_bl, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, ((data->map->height - 1) * data->px));
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->map->graphic.corner_br, &data->px, &data->px);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, ((data->map->width - 1) * data->px),
		((data->map->height - 1) * data->px));
}

void	display_map(t_data *data)
{
	display_corners(data);
	display_walls(data);
	display_content(data);
}
