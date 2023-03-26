/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:06:05 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/23 20:06:09 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_mov_count(t_data *data, int mov_count)
{
	char		*mov_count_s;

	ft_printf("\nNumber of movements: %i\n", mov_count);
	mov_count_s = ft_itoa(mov_count);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->map->sprites->corner_tl, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 17, 0xFFFFFF, mov_count_s);
	free(mov_count_s);
}

void	setup_sprites02(t_data *data)
{
	data->map->sprites->collectible02 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible2_01.xpm", &data->px, &data->px);
	data->map->sprites->collectible03 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible03.xpm", &data->px, &data->px);
	data->map->sprites->collectible04 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible04.xpm", &data->px, &data->px);
	data->map->sprites->exit01 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit01.xpm", &data->px, &data->px);
	data->map->sprites->exit02 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit02.xpm", &data->px, &data->px);
	data->map->sprites->exit03 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit03.xpm", &data->px, &data->px);
	data->map->sprites->exit_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit_player.xpm", &data->px, &data->px);
	data->map->sprites->player_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_up.xpm", &data->px, &data->px);
	data->map->sprites->player_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_down.xpm", &data->px, &data->px);
	data->map->sprites->player_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_left.xpm", &data->px, &data->px);
	data->map->sprites->player_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player_right.xpm", &data->px, &data->px);
}

void	setup_sprites(t_data *data)
{
	data->map->sprites->player01 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player01.xpm", &data->px, &data->px);
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
			"./images/collectible1_01.xpm", &data->px, &data->px);
	data->map->sprites->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit.xpm", &data->px, &data->px);
	setup_sprites02(data);
}
