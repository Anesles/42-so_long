/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:29:32 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/20 19:33:16 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_rectangle(t_map map, int line_len)
{
	int		i;
	char	**tmap;
	int		len;

	tmap = map.map;
	i = 1;
	len = 0;
	while (i < map.n_lines)
	{
		len = ft_strlen(tmap[i]);
		if (len != line_len)
			send_error("Error\nNot a rectangle.");
		i++;
	}
	return (line_len);
}

static void	check_closed(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.n_lines)
	{
		if (i == 0 || i == map.n_lines - 1)
		{
			j = 0;
			while (j < map.n_cols)
			{
				if (map.map[i][j++] != '1')
					send_error("Error\nMap not closed (top or bottom).");
			}
		}
		else
			if (map.map[i][0] != '1' || map.map[i][map.n_cols - 1] != '1')
				send_error("Error\nMap not closed (sides).");
		i++;
	}
}

static t_map	add_element(t_map map, char c, int x, int y)
{
	if (c == 'P')
	{
		if (map.p_pos[0] == 0)
		{
			map.p_pos[0] = x;
			map.p_pos[1] = y;
		}
		else
			send_error("Error\nMap has more then 1 P.");
	}
	else if (c == 'E')
	{
		if (map.e_pos[0] == 0)
		{
			map.e_pos[0] = x;
			map.e_pos[1] = y;
		}
		else
			send_error("Error\nMap has more then 1 E.");
	}
	return (map);
}

static void	check_elements(t_map *map)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 0;
	while (i < (*map).n_lines)
	{
		if (i != 0 && i != (*map).n_lines - 1)
		{
			j = 0;
			while (j < (*map).n_cols)
			{
				if ((*map).map[i][j] == 'E' || (*map).map[i][j] == 'P')
				{
					(*map) = add_element((*map), (*map).map[i][j], i, j);
					valid += 1;
				}
				j++;
			}
		}
		i++;
	}
	if (valid != 2)
		send_error("Error\nMissing either P or E.");
}

void	check_valid(t_map *map)
{
	int	line_len;

	map->e_pos[0] = 0;
	map->p_pos[0] = 0;
	line_len = ft_strlenn(map->map[0]);
	if (line_len == 0)
		send_error("Error\nEmpty line found.");
	map->n_cols = check_rectangle(*map, line_len);
	check_closed(*map);
	check_elements(map);
	check_extra(*map);
	flood_fill(map);
}
