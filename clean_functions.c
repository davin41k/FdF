/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:02:20 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 17:41:09 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_array_coord_and_graph(t_fdf *fdf)
{
	int		idx;

	idx = -1;
	while (++idx < fdf->count.y)
		free(fdf->array_y_z[idx]);
	free(fdf->coord->color);
	free(fdf->coord);
	free(fdf->graph->win_ptr);
	free(fdf->graph->mlx_ptr);
	free(fdf->graph);
}

void	resize_window(t_fdf *fdf)
{
	static int	scale;

	if (scale == 0)
	{
		mlx_destroy_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		fdf->win_width = WIN_HD_WIDTH;
		fdf->win_height = WIN_HD_HEIGHT;
		scale = 1;
		sicle_draw(fdf);
	}
	else
	{
		mlx_destroy_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
		fdf->win_width = WIN_FHD_WIDTH;
		fdf->win_height = WIN_FHD_HEIGHT;
		scale = 0;
		sicle_draw(fdf);
	}
}

void	change_projection(t_fdf *fdf, int projection)
{
	fdf->projection = projection - 18;
	mlx_clear_window(fdf->graph->mlx_ptr, fdf->graph->win_ptr);
	draw_figure(fdf);
}

int		fdf_exit(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}
