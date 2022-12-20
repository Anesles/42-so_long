/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:27:55 by brumarti          #+#    #+#             */
/*   Updated: 2022/12/14 16:12:02 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	animations(t_vars *vars)
{
	vars->fps++;
	if (vars->fps == 100000)
	{
		if (vars->state == 0)
		{
			mlx_put_image_to_window(vars->mlx.ptr, vars->mlx.win, \
					vars->imgs.p2.ptr, vars->map.p_pos[1] * 50, \
					vars->map.p_pos[0] * 50);
			vars->state = 1;
		}
		else
		{
			mlx_put_image_to_window(vars->mlx.ptr, vars->mlx.win, \
					vars->imgs.p.ptr, vars->map.p_pos[1] * 50, \
					vars->map.p_pos[0] * 50);
			vars->state = 0;
		}
		vars->fps = 0;
	}
	return (0);
}

void	update_moves(t_vars *vars)
{
	char	str[30];
	
	snprintf(str, 30, "Moves: %d", vars->mlx.moves);
	mlx_string_put(vars->mlx.ptr, vars->mlx.win, ((vars->map.n_cols * 50) / 2) - 25, \
		vars->map.n_lines * 50 + 25, 0x000000, str);
	snprintf(str, 30, "Moves: %d", ++vars->mlx.moves);
	mlx_string_put(vars->mlx.ptr, vars->mlx.win, ((vars->map.n_cols * 50) / 2) - 25, \
		vars->map.n_lines * 50 + 25, 0xFFFFFF, str);
}
