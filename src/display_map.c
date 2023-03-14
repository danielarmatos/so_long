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
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	data->map->sprites = sprites;

		ft_printf("\n======Ola02");
	data->map->sprites->player01 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player01.xpm", &data->px, &data->px);	
		ft_printf("\n======Ola03");
	data->map->sprites->obstacle = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/obstacle01.xpm", &data->px, &data->px);
	data->map->sprites->corner_tl = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/corner_tl.xpm", &data->px, &data->px);
	data->map->sprites->corner_bl = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/corner_bl.xpm", &data->px, &data->px);
	data->map->sprites->corner_tr = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/corner_tr.xpm", &data->px, &data->px);
	data->map->sprites->corner_br = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/corner_br.xpm", &data->px, &data->px);
	data->map->sprites->wall_h = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/wall_h.xpm", &data->px, &data->px);
	data->map->sprites->wall_p = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/wall_p.xpm", &data->px, &data->px);
	data->map->sprites->bg = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/background.xpm", &data->px, &data->px);
	data->map->sprites->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible.xpm", &data->px, &data->px);
	data->map->sprites->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit.xpm", &data->px, &data->px);
	ft_printf("\n======Ola03");
}

void	display_walls(t_data *data)
{
	int	i;

	i = 1;
	while (i < (data->map->width - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map->sprites->wall_h, (i * data->px), 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->sprites->wall_h,
			(i * data->px), ((data->map->height - 1) * data->px));
		i++;
	}
	i = 1;
	while (i < (data->map->height - 1))
	{
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->map->sprites->wall_p, 0, (i * data->px));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->sprites->wall_p,
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
	ft_printf("\n======Ola");
	ft_printf("\n+++%c", data->map->map_array[0][0]);
	setup_sprites(data);
	
	display_corners(data);
	display_walls(data);
	display_content(data);
	ft_printf("\n+++01+++%c", data->map->map_array[0][0]);
}
