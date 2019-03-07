/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:42:32 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/07 20:31:13 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//	в точках сразу будут правильные координаты
//	например p_1 {x: 130, y: 70}, p_2 {x: 160, y: 82}

void	draw_line(t_fdf *fdf, t_point p_one, t_point p_two)
{
	t_point		delta;		//сколько кому нужно сдвигаться (пикселов) за шаг
	t_point		abs_value;	// абсолютное значение => x | y будет сдвигаться на 1 пиксел
	int			max_value;	//сколько нужно прошагать
	int			sign;		//знак, в какую сторону нужно идти
	int			idx;

	idx = 0;
	sign = p_two.x > p_one.x ? 1 : -1;
	abs_value.x = (p_two.x - p_one.x) * sign;
	sign = p_two.y > p_one.y ? 1 : -1;
	abs_value.y = (p_two.y - p_one.y) * sign;
	delta.x = abs_value.x >= abs_value.y ? 1 : abs_value.x / abs_value.y; 
	delta.y = abs_value.y > abs_value.x ? 1 : abs_value.y / abs_value.x; 
	max_value = abs_value.x > abs_value.y ? abs_value.x : abs_value.y;
	mlx_pixel_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
	p_one.x, p_one.y, fdf->graph->color);	// рисуем первый пиксел, потов все остальные со смещением
	while (++idx <= max_value)
	{
		mlx_pixel_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		p_one.x += delta.x, p_one.y += delta.y, fdf->graph->color);
	}
}

void	draw_horiz_lines(t_fdf *fdf)
{
	int			**arr;
	t_point		p_one;
	t_point		p_two;
	int			i;
	int			j;

	arr = fdf->array_y_z;
	// p_one.x = fdf->start_pos.x + (fdf->delta.x);
	// p_one.y = fdf->start_pos.y;
	// p_two.x = fdf->start_pos.x + (fdf->delta.x * 2);
	// p_two.y = fdf->start_pos.y;
	i = -1;
	while (++i < fdf->count.y)
	{
		j = 0;
		while (++j < fdf->count.x)
		{
			p_one.x = fdf->start_pos.x + (fdf->delta.x * (j - 1));
			p_one.y = fdf->start_pos.y + (fdf->delta.y * (i));
			p_two.x = fdf->start_pos.x + (fdf->delta.x * (j));
			p_two.y = fdf->start_pos.y + (fdf->delta.y * (i));
			draw_line(fdf, p_one, p_two);
		}
	}
	printf("P_ONE: %f,  %f\tP_TWO: %f,  %f\n", p_one.x, p_one.y, p_two.x, p_two.y);
}

void	draw_vert_lineas(t_fdf *fdf)
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
		j = 0;
		while (++j < fdf->count.y)
		{
			p_one.x = fdf->start_pos.x + (fdf->delta.x * (i));
			p_one.y = fdf->start_pos.y + (fdf->delta.y * (j - 1));
			p_two.x = fdf->start_pos.x + (fdf->delta.x * (i));
			p_two.y = fdf->start_pos.y + (fdf->delta.y * (j));
			draw_line(fdf, p_one, p_two);
		}
	}
}

void	sicle_draw(t_fdf *fdf)
{
	fdf->graph->mlx_ptr = mlx_init();
	fdf->graph->win_ptr = mlx_new_window(fdf->graph->mlx_ptr,
	WIN_WIDTH, WIN_HEIGHT, fdf->title);
	draw_figure(fdf);
	mlx_hook(fdf->graph->win_ptr, 2, 0, fdf_exit, fdf_exit);
	mlx_loop(fdf->graph->mlx_ptr);
}

int		fdf_exit(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

void	draw_figure(t_fdf *fdf)
{
	draw_horiz_lines(fdf);
	draw_vert_lineas(fdf);
}