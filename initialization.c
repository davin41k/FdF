/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:19:34 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/07 20:27:24 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf **fdf, char *file_name)
{
	t_fdf	*new_fdf;

	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	new_fdf = *fdf;	
	new_fdf->graph = (t_graph *)malloc(sizeof(t_graph));
	new_fdf->graph->color = 0xFFFFFF;
	new_fdf->title = "FdF";
	//printf("%s\n", file_name);
	new_fdf->file_name = file_name;
}

// после norminate
void	fdf_coord_init(t_fdf *fdf)
{
	fdf->start_pos.x = WIN_WIDTH / 4;
	fdf->start_pos.y = WIN_HEIGHT / 4;
	fdf->delta.x = (WIN_WIDTH / fdf->count.x) / 2;
	fdf->delta.y = (WIN_HEIGHT / fdf->count.y) / 2;
	fdf->scale.x = fdf->delta.x * 1.5;
	fdf->scale.y = fdf->delta.y * 1.5;
	printf("start_x: %f\tstart_y: %f\n", fdf->start_pos.x, fdf->start_pos.y);
}

//	написал бразенхельм, рисует сетку
//	смещение фигуры