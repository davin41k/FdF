/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:19:34 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 19:42:52 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_init(t_fdf **fdf, char *file_name)
{
	t_fdf	*new_fdf;

	*fdf = (t_fdf *)malloc(sizeof(t_fdf));
	new_fdf = *fdf;
	new_fdf->graph = (t_graph *)malloc(sizeof(t_graph));
	new_fdf->title = "FdF";
	new_fdf->file_name = file_name;
	new_fdf->graph->help_info = 0;
	new_fdf->projection = 0;
}

void		fdf_coord_init(t_fdf *fdf)
{
	fdf->win_width = WIN_FHD_WIDTH;
	fdf->win_height = WIN_FHD_HEIGHT;
	fdf->start_pos.x = fdf->win_width / 5;
	fdf->start_pos.y = fdf->win_height / 5;
	fdf->start_pos.z = 3;
	fdf->save_start_pos = fdf->start_pos;
	fdf->delta.x = (fdf->win_width / fdf->count.x) / 2;
	fdf->delta.y = (fdf->win_height / fdf->count.y) / 2;
	fdf->delta.z = 3;
	fdf->start_delta = fdf->delta;
	fdf->scale.x = fdf->win_width / 5;
	fdf->scale.y = fdf->win_height / 5;
	fdf->scale.z = 0;
	fdf->vert_count = fdf->count.x * fdf->count.y;
	get_coord(fdf);
}
