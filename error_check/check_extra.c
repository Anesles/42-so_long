/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:06:28 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/26 00:52:21 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	check_extra(t_map map)
{
	int		i;
	int		j;
	char	c;
	char	**tmap;

	tmap = map.map;
	i = 0;
	while (i < map.n_lines)
	{
		j = 0;
		while (j < map.n_cols)
		{
			c = tmap[i][j];
			if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C')
				send_error("Error\nFound an invalid char.");
			j++;
		}
		i++;
	}
}
