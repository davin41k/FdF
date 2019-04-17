/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:42:32 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/13 17:59:18 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, t_point p_one, t_point p_two)
{
	t_point		delta;
	t_point		abs_value;
	int			max_value;
	int			sign[2];
	int			idx;

	idx = 0;
	sign[0] = p_two.x > p_one.x ? 1 : -1;
	abs_value.x = (p_two.x - p_one.x) * sign[0];
	sign[1] = p_two.y > p_one.y ? 1 : -1;
	abs_value.y = (p_two.y - p_one.y) * sign[1];
	delta.x = abs_value.x >= abs_value.y ? 1 : abs_value.x / abs_value.y;
	delta.y = abs_value.y > abs_value.x ? 1 : abs_value.y / abs_value.x;
	max_value = abs_value.x > abs_value.y ? abs_value.x : abs_value.y;
	mlx_pixel_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
	p_one.x, p_one.y, p_one.color);
	delta.x *= sign[0];
	delta.y *= sign[1];
	while (++idx <= max_value)
	{
		mlx_pixel_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		p_one.x += delta.x, p_one.y += delta.y, p_one.color);
	}
}

void	draw_horiz_lines(t_fdf *fdf, int projection)
{
	int			**arr;
	t_point		p_one;
	t_point		p_two;
	int			i;
	int			j;

	arr = fdf->array_y_z;
	i = -1;
	while (++i < fdf->count.y)
	{
		j = -1;
		while (++j < fdf->count.x - 1)
		{
			p_one.z = (arr[i][j] + fdf->scale.z) * fdf->delta.y / fdf->delta.z;
			p_one.x = j * fdf->delta.y + fdf->start_pos.x;
			p_one.y = i * fdf->delta.y + fdf->start_pos.y;
			p_one.color = fdf->coord->color[(int)(j + i * fdf->count.x)];
			p_two.z = (arr[i][j + 1] + fdf->scale.z) *
			fdf->delta.y / fdf->delta.z;
			p_two.x = (j + 1) * fdf->delta.y + fdf->start_pos.x;
			p_two.y = i * fdf->delta.y + fdf->start_pos.y;
			do_projection(&p_one, &p_two, projection);
			draw_line(fdf, p_one, p_two);
		}
	}
}

void	draw_vert_lineas(t_fdf *fdf, int projection)
{
	int			**arr;
	t_point		p_one;
	t_point		p_two;
	int			i;
	int			j;

	arr = fdf->array_y_z;
	i = -1;
	while (++i < fdf->count.x)
	{
		j = -1;
		while (++j < fdf->count.y - 1)
		{
			p_one.z = (arr[j][i] + fdf->scale.z) * fdf->delta.y / fdf->delta.z;
			p_one.x = i * fdf->delta.y + fdf->start_pos.x;
			p_one.y = j * fdf->delta.y + fdf->start_pos.y;
			p_one.color = fdf->coord->color[(int)(fdf->count.x * j + i)];
			p_two.z = (arr[j + 1][i] + fdf->scale.z) *
			fdf->delta.y / fdf->delta.z;
			p_two.x = i * fdf->delta.y + fdf->start_pos.x;
			p_two.y = (j + 1) * fdf->delta.y + fdf->start_pos.y;
			do_projection(&p_one, &p_two, projection);
			draw_line(fdf, p_one, p_two);
		}
	}
}

void	sicle_draw(t_fdf *fdf)
{
	fdf->graph->mlx_ptr = mlx_init();
	fdf->graph->win_ptr = mlx_new_window(fdf->graph->mlx_ptr,
	fdf->win_width, fdf->win_height, fdf->title);
	draw_figure(fdf);
	mlx_hook(fdf->graph->win_ptr, 2, 0, hotkeys, fdf);
	mlx_hook(fdf->graph->win_ptr, 4, 0, mouse_scroll, fdf);
	mlx_loop(fdf->graph->mlx_ptr);
}

void	draw_figure(t_fdf *fdf)
{
	draw_horiz_lines(fdf, fdf->projection);
	draw_vert_lineas(fdf, fdf->projection);
	drow_text(fdf);
}
