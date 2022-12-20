/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:44:57 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/20 19:33:07 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
static void	print_map(char **map, int max_l, int x, int y)
{
	int	i;

	i = 0;
	while (i < max_l)
		ft_printf("%s\n", map[i++]);
	ft_printf("x:%d  y:%d\n", x, y);
}
*/
static void	fill(char	***new_map, int x, int y, t_map map)
{
	if (x < 0 || x >= map.n_lines || y < 0 || y >= map.n_cols
		|| (*new_map)[x][y] == '1' || (*new_map)[x][y] == ' ')
		return ;
	else
	{
		(*new_map)[x][y] = ' ';
		fill(new_map, x - 1, y, map);
		fill(new_map, x + 1, y, map);
		fill(new_map, x, y - 1, map);
		fill(new_map, x, y + 1, map);
	}
}

static	int	check_collect(char c)
{
	if (c != ' ')
		send_error("Error\nInvalid path(Collectible unreachable).");
	return (1);
}

static void	check_path(char **fill_map, t_map *map)
{
	int		i;
	int		j;
	int		valid;

	map->n_collec = 0;
	if (fill_map[map->e_pos[0]][map->e_pos[1]] != ' ')
		send_error("Error\nInvalid path (Exit not reachable).");
	i = 1;
	valid = 0;
	while (i < map->n_lines)
	{
		j = 1;
		while (j < map->n_cols)
		{
			if (map->map[i][j] == 'C')
			{
				map->n_collec += 1;
				valid = check_collect(fill_map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (valid == 0)
		send_error("Error\nNo collectibles.");
}

void	flood_fill(t_map *map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char **) malloc(map->n_lines * sizeof(char *));
	while (i < map->n_lines)
	{
		new_map[i] = ft_strdup(map->map[i]);
		i++;
	}
	fill(&new_map, map->p_pos[0], map->p_pos[1], *map);
	check_path(new_map, map);
	i = 0;
	while (i < map->n_lines)
		free(new_map[i++]);
	free(new_map);
}
