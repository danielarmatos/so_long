/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:10:54 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/02 19:56:53 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**save_map(char *map_file, t_map *map)
{
	int		fd;
	char	**map_array;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	map_array = malloc(map->height * sizeof(char *));
	if (!map_array)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_array[i] = line;
		i++;
	}
	close(fd);
	return (map_array);
}

int	read_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		write(1, &line[i], 1);
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C'
			|| line[i] == 'E' || line[i] == 'P' || line[i] == '\n')
			i++;
		else
		{
			ft_printf("\n\nError\n\033[1;31mMap contains invalid characters\033[0m\n");
			return (0);
		}
	}
	return (i - 1);
}

int	check_width(char *line, int width)
{
	int	x;

	x = read_line(line);
	if (x == 0)
		return (0);
	if (width == 0)
		width = x;
	if (width != x)
	{
		ft_printf("\nError\n\033[1;31mWidth of the map is not constant.\033[0m\n");
		return (0);
	}
	return (width);
}

int	read_map(char *map_file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->width = check_width(line, map->width);
		if (map->width == 0)
		{
			free(line);
			close(fd);
			return (0);
		}
		map->height++;
		free(line);
	}
	close(fd);
	return (1);
}

int	validate_map(char *map_file, t_map *map)
{
	char	**map_array;
	char	**map_array_val;

	if (read_map(map_file, map) == 1)
	{
		map_array = save_map(map_file, map);
		map_array_val = save_map(map_file, map);
		map->map_array = map_array;
		map->map_array_val = map_array_val;
		if (validate_map02(map) == 1)
		{
			if (validate_path(map) == 1)
				return (1);
		}
		else
		{
			ft_printf("\nError saving map\n");
			destroy_map_array(map);
			free(map->map_array);
			free(map->map_array_val);
		}
	}
	return (0);
}
