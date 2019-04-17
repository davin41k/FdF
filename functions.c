/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:20:35 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/13 16:08:06 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_array_count(char **array)
{
	int		count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	drow_text(t_fdf *fdf)
{
	if (!fdf->graph->help_info)
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 50, 0x9400D3, "Press I for help");
	else
	{
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 50, 0x9400D3, "Use arrows (<-, ->, etc.) for moving the figure");
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 70, 0x9400D3, "Change projections - [upper] 1, 2, and 3 keys");
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 90, 0x9400D3, "Reset the figure position - R");
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 110, 0x9400D3, "Moving on Z axis - mouse scroll");
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 130, 0x9400D3, "Change resolution (HD/FHD)- TAB");
		mlx_string_put(fdf->graph->mlx_ptr, fdf->graph->win_ptr,
		50, 150, 0x9400D3, "Change size the figure - right '+', '-'");
	}
}

void	figure_restart(int key, t_fdf *fdf)
{
	if (key == 15)
	{
		fdf->start_pos.x = fdf->save_start_pos.x;
		fdf->start_pos.y = fdf->save_start_pos.y;
		fdf->delta.z = fdf->start_pos.z;
		fdf->delta.x = fdf->start_delta.x;
		fdf->delta.y = fdf->start_delta.y;
		fdf->scale.z = 0;
	}
}
