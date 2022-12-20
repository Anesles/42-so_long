/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:03:01 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/02 01:03:06 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	get_lines(int fd)
{
	int		len;
	char	*line;

	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (len);
		free(line);
		len++;
	}
}

static void	get_map(int fd, char *file, t_map *map)
{
	int		i;
	char	*line;

	map->n_lines = get_lines(fd);
	map->map = (char **)malloc(map->n_lines * sizeof(char *));
	if (!map->map)
		send_error("Error\nFailed map alloc.");
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < map->n_lines)
	{
		line = get_next_line(fd);
		map->map[i] = ft_strtrim(line, "\n\r\t\v\f");
		free(line);
		if (!map->map[i])
		{
			free_map(*map);
			send_error("Error\nFailed map[] alloc.");
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		fd;

	vars.map.map = 0;
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			send_error("Error\nBad file extension.");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			send_error("Error\nFailed to open file.");
		get_map(fd, (char *)argv[1], &vars.map);
		check_valid(&vars.map);
		game_main(vars);
		free_map(vars.map);
		close(fd);
	}
	else
		send_error("Error\nMore than 1 argument.");
}
