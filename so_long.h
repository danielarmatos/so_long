/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:44 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/01/28 19:22:59 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include "minilibx/mlx.h"

#include <X11/keysym.h>
#include <X11/X.h>

#define MLX_ERROR 1

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
/*
typedef struct	s_sprites
{
	char	*player01;
}				t_sprites;
*/
typedef struct	s_graphic
{
	char	*player01;
	char	*obstacle;
	char	*wall02;
	char	*collectible;
	char	*exit;
	char	*corner_tl;
	char	*corner_bl;
	char	*corner_tr;
	char	*corner_br;
	char	*wall_h;
	char	*wall_p;
	char	*bg;
	
}				t_graphic;

typedef struct	s_map
{
	int			width;
	int			height;
	int			collectibles;
	int			exit;
	int			starting_pos;
	char			**map_array;
	int			image_size;
	int			curr_pos_x;
	int			curr_pos_y;
	int			collected_col;
	t_graphic		graphic;
	//t_sprites		sprites;
}				t_map;




typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
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
	int	px;
}	t_data;

int	validate_map(char *map_file, t_map *map);
int validate_map02(t_map *map);
t_map  validate_path(char **map, int height, int width);
int	render_map(t_map *map);
void    display_map(t_data *data);
void    display_content(t_data *data);
void    destroy_map(t_data *data);
//void    update_game(t_data *data);
int key_hook(int key, t_data *data);

#endif
