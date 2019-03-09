/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:18:07 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/08 18:04:42 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate_right(t_point *p_one, t_point *p_two)
{
    int     new_x;
    int     new_y;

    new_x = (p_one->x + p_one->y) * cos(10);
    new_y = (p_one->x - p_one->y) * sin(10) - p_one->z;
    p_one->x = new_x;
    p_one->y = new_y;
    new_x = (p_two->x + p_two->y) * cos(10);
    new_y = (p_two->x - p_two->y) * sin(10) - p_two->z;
    p_two->x = new_x;
    p_two->y = new_y;
}

void	draw_rotate_vert_lineas(t_fdf *fdf)
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
			rotate_right(&p_one, &p_two);
			draw_line(fdf, p_one, p_two);
		}
	}
}
