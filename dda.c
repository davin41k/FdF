/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:47:06 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/28 12:49:17 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int deltaX;
	int     deltaY;
	int     length;
	double     dX;
	double     dY;
	double     x, y;

	deltaX = x1 - x2 > 0 ? x1 - x2 : (x1 - x2) * -1;
	deltaY = y1 - y2 > 0 ? y1 - y2 : (y1 - y2) * -1;

	length = deltaX > deltaY ? deltaX : deltaY;
	printf("deltax %d\tdeltay %d\n", deltaX, deltaY);
	if (length == 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
		return ;
	}

	dX = (double)(x2 - x1) / (double)length;
	dY = (double)(y2 - y1) / (double)length;
	printf("dX %f\tdY %f\n", dX, dY);

	x = x1;
	y = y1;
	printf("X:\t%f and Y:\t%f\tLEN:\t%d\n", dX, dX, length);

	while (length--)
	{
		x += dX;
		y += dY;
		mlx_pixel_put(mlx_ptr, win_ptr, x,  y, 0xFFFFFF);
	}
	printf("X:\t%f and Y:\t%f\tLEN:\t%d\n", dX, dX, length);
}