/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:08:41 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/09 17:36:01 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hotkeys(int key, t_fdf *fdf)
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
	if (key == 0)
		rotate(key, fdf);
	if (key == 53)
		fdf_exit(key, fdf);
	return (0);
}

void	figure_move(int key, t_fdf *fdf)
{
	if (key == 124)		//left
		fdf->start_pos.x += WIN_WIDTH / 10;
	if (key == 123)		//right
		fdf->start_pos.x -= WIN_WIDTH / 10;
	if (key == 125)	//up
		fdf->start_pos.y += WIN_HEIGHT / 10;
	if (key == 126)	//down
		fdf->start_pos.y -= WIN_HEIGHT / 10;
}

void	rotate (int key, t_fdf *fdf)
{
	if (key == 0)
	{
		mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		draw_rotate_vert_lineas(fdf);
	}

}

void	figure_scale(int key, t_fdf *fdf)
{
	if (key == 69)
	{
		fdf->start_pos.x -= fdf->scale.x / 2;
		fdf->start_pos.y -= fdf->scale.y / 2;
		fdf->delta.x += fdf->start_delta.x / 2;
		fdf->delta.y += fdf->start_delta.y / 2;
	}
	if (key == 78)
	{
		fdf->start_pos.x += fdf->scale.x / 2;
		fdf->start_pos.y += fdf->scale.y / 2;
		fdf->delta.x -= fdf->start_delta.x / 2;
		fdf->delta.y -= fdf->start_delta.y / 2;
		
	}
}
/*
if (key == 69)
	{
		fdf->start_pos.x += fdf->start_pos.x < fdf->save_start_pos.x ? 0 :fdf->scale.x;
		fdf->start_pos.y += fdf->start_pos.y < fdf->save_start_pos.y ? 0 :fdf->scale.y;
		//fdf->start_pos.y += fdf->scale.y;
		fdf->delta.x += fdf->delta.x <= fdf->start_delta.x ?
		fdf->delta.x * 2 : fdf->start_delta.x;
		fdf->delta.y += fdf->delta.y <= fdf->start_delta.y ?
		fdf->delta.y * 2 : fdf->start_delta.y;
		//fdf->delta.y += fdf->start_delta.y;
	}
	if (key == 78)
	{
		fdf->start_pos.x -= fdf->start_pos.x <= fdf->save_start_pos.x ? 0 : fdf->scale.x;
		fdf->start_pos.y -= fdf->start_pos.y <= fdf->save_start_pos.y ? 0 : fdf->scale.y;
		//fdf->start_pos.y -= fdf->scale.y;
		fdf->delta.x -= fdf->delta.x <= fdf->start_delta.x ?
		fdf->delta.x / 2 : fdf->start_delta.x;
		fdf->delta.y -= fdf->delta.y <= fdf->start_delta.y ?
		fdf->delta.y / 2 : fdf->start_delta.y;
	}
*/

void	figure_restart(int key, t_fdf *fdf)
{
	if (key == 15)
	{
		fdf->start_pos.x = fdf->save_start_pos.x;
		fdf->start_pos.y = fdf->save_start_pos.y;
		fdf->delta.x = fdf->start_delta.x;
		fdf->delta.y = fdf->start_delta.y;
		//fdf->graph->color = 0xFFFFFF;
	}
}

int		fdf_exit(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}
