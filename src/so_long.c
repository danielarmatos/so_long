/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:40:17 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/18 20:15:48 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->starting_pos = 0;
	map->exit = 0;
	map->curr_pos_x = 0;
	map->curr_pos_y = 0;
	map->collected_col = 0;
}

int	check_file_type(char *map_file)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 3;
	ber = ".ber";
	while (map_file[i])
		i++;
	i--;
	while (j >= 0)
	{
		if (map_file[i] != ber[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

void	so_long(char **argv)
{
	t_map	*map;

	if (check_file_type(argv[1]) == 0)
	{
		ft_printf("\nError\n\033[1;31mMap file type is INVALID!\033[0m\n");
		return ;
	}
	map = malloc(sizeof(t_map));
	setup_map(map);
	if (validate_map(argv[1], map) == 0)
	{
		ft_printf("\nMap is INVALID!\n");
		free(map);
		return ;
	}
	else
	{
		if (render_map(map) == 0)
		{
			ft_printf("\nError\n\033[1;31mError rendering map!\033[0m\n");
			free(map);
		}
	}	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		so_long(argv);
	}
	else
		ft_printf("\nError\n\033[1;31mNumber of Arguments is INVALID!\033[0m\n");
}
