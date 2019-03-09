/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:19:34 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/09 18:20:08 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_init(t_fdf **fdf, char *file_name)
{
	t_fdf	*new_fdf;

	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	new_fdf = *fdf;	
	new_fdf->graph = (t_graph *)malloc(sizeof(t_graph));
	//new_fdf->graph->color = 0xFFFFFF;
	new_fdf->title = "FdF";
	//printf("%s\n", file_name);
	new_fdf->file_name = file_name;
}

// после norminate
void		fdf_coord_init(t_fdf *fdf)
{
	fdf->start_pos.x = WIN_WIDTH / 4;
	fdf->start_pos.y = WIN_HEIGHT / 4;
	fdf->save_start_pos = fdf->start_pos;
	fdf->delta.x = (WIN_WIDTH / fdf->count.x) / 2;
	fdf->delta.y = (WIN_HEIGHT / fdf->count.y) / 2;
	fdf->delta.z = 10;
	fdf->start_delta = fdf->delta;
	fdf->scale.x = WIN_WIDTH / 5;
	fdf->scale.y = WIN_HEIGHT / 5;
	fdf->vert_count = fdf->count.x * fdf->count.y;  //надеюсь уже инициализованы...
}

//множение на кол-во всех точек (x * y);
t_coord		*coord_init(t_fdf *fdf)
{
	t_coord		*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	coord->x = (int *)malloc(sizeof(int) * fdf->vert_count);
	coord->y = (int *)malloc(sizeof(int) * fdf->vert_count);
	coord->z = (int *)malloc(sizeof(int) * fdf->vert_count);
	coord->color = (int *)malloc(sizeof(int) * fdf->vert_count);
	printf("VERT_COORD: %d\n", fdf->vert_count);
	return (coord);	
}

//	написал бразенхельм, рисует сетку
//	смещение фигуры