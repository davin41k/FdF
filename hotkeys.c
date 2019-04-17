/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:08:41 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 20:01:20 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hotkeys(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		if (fdf->graph->help_info == 0)
			fdf->graph->help_info = 1;
		else
			fdf->graph->help_info = 0;
		draw_figure(fdf);
	}
	return (hotkeys_one(key, fdf));
}

int		hotkeys_one(int key, t_fdf *fdf)
{
	if ((key > 122 && key < 127) || (key > -1 && key < 3) || key == 13)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		figure_move(key, fdf);
		draw_figure(fdf);
	}
	if (key == 69 || key == 78)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		figure_scale(key, fdf);
		draw_figure(fdf);
	}
	if (key == 15)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		figure_restart(key, fdf);
		draw_figure(fdf);
	}
	if (key == 48)
		resize_window(fdf);
	if (key == 53)
		fdf_exit(key, fdf);
	if (key == 18 || key == 19 || key == 20)
		change_projection(fdf, key);
	return (0);
}

int		mouse_scroll(int key, int x, int y, t_fdf *fdf)
{
	if (key == SCROLL_UP)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		fdf->scale.z += 4;
		draw_figure(fdf);
	}
	else if (key == SCROLL_DOWN)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		fdf->scale.z -= 4;
		draw_figure(fdf);
	}
	x++;
	y++;
	x--;
	y--;
	return (0);
}

void	figure_move(int key, t_fdf *fdf)
{
	if (key == 124)
		fdf->start_pos.x += fdf->win_width / 10;
	if (key == 123)
		fdf->start_pos.x -= fdf->win_width / 10;
	if (key == 125)
		fdf->start_pos.y += fdf->win_height / 10;
	if (key == 126)
		fdf->start_pos.y -= fdf->win_height / 10;
}

void	figure_scale(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
	if (key == 69)
	{
		fdf->start_pos.x -= fdf->scale.x / 3;
		fdf->start_pos.y -= fdf->scale.y / 3;
		fdf->delta.x += fdf->start_delta.x / 3;
		fdf->delta.y += fdf->start_delta.y / 3;
	}
	if (key == 78)
	{
		if (fdf->delta.x <= 0.1 || fdf->delta.y <= 0.1)
		{
			fdf->delta.x = 0;
			fdf->delta.y = 0;
		}
		else
		{
			fdf->start_pos.x += fdf->scale.x / 3;
			fdf->start_pos.y += fdf->scale.y / 3;
			fdf->delta.x -= fdf->start_delta.x / 3;
			fdf->delta.y -= fdf->start_delta.y / 3;
		}
	}
	draw_figure(fdf);
}
