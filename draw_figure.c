/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:49:57 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/28 18:23:06 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_figure(void *mlx_ptr, void *win_ptr, t_figure *figura)
{
	int		y;
	int		x;
	int		delta_X;
	int		delta_Y;

	delta_X = figura->start_position[1];
	delta_Y = figura->start_position[0];
	y = -1;
	while (++y < figura->start_position[0])
	{
		x = -1;
		while (++x < figura->start_position[1])
			draw_line(mlx_ptr, win_ptr, delta_X, delta_Y, delta_X += 10, delta_Y += 10);
	}
}