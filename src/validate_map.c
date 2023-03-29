/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:10:54 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/03/18 20:25:28 by dreis-ma         ###   ########.fr       */
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
		i++;
	}
	if (line [i - 1] != '\n')
		return (i);
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
		return (0);
	return (width);
}

int	read_map(char *map_file, t_map *map)
{
	int		fd;
	char	*line;
	int		res;

	res = 1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_printf("\nError\n\033[1;31mThe file could not be opened\033[0m\n");
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->width = check_width(line, map->width);
		if (map->width == 0)
			res = 2;
		if (validate_characters(line) == 0)
			res = 3;
		map->height++;
		free(line);
	}
	close(fd);
	return (res);
}

int	validate_map(char *map_file, t_map *map)
{
	char	**map_array;
	char	**map_array_val;
	char	result;

	result = read_map(map_file, map);
	if (result == 1)
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
		destroy_map_array(map);
		free(map->map_array);
		free(map->map_array_val);
	}
	else if (result == 2)
		ft_printf("\nError\n\033[1;31mWidth of the map is not constant.\033[0m\n");
	else if (result == 3)
		ft_printf("\n\nError\n\033[1;31mMap has invalid characters.\033[0m\n");
	return (0);
}
