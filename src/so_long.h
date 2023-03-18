/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:44 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/14 18:17:01 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include "../minilibx/mlx.h"

# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_sprites
{
	void	*player01;
	void	*obstacle;
	void	*wall02;
	void	*collectible;
	void	*exit;
	void	*corner_tl;
	void	*corner_bl;
	void	*corner_tr;
	void	*corner_br;
	void	*wall_h;
	void	*wall_p;
	void	*bg;
}			t_sprites;

typedef struct s_map
{
	int			width;
	int			height;
	int			collectibles;
	int			exit;
	int			starting_pos;
	char		**map_array;
	char		**map_array_val;
	int			image_size;
	int			curr_pos_x;
	int			curr_pos_y;
	int			validation_col;
	int			validation_exit;
	int			collected_col;
	t_sprites	*sprites;
}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_map	*map;
	int		px;
}	t_data;

int		validate_map(char *map_file, t_map *map);
int		validate_map02(t_map *map);
int		validate_path(t_map *map);
int		render_map(t_map *map);
void	display_map(t_data *data);
void	display_content(t_data *data);
void	destroy_map(t_data *data);
int		key_hook(int key, t_data *data);
int		close_window(void);
void	display_exit(t_data *data, int x, int y);
void	destroy_map_array(t_map *map);
int		close_window(void);

#endif
