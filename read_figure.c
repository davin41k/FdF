/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:46:02 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 17:51:47 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		view_projections(double *x, double *y, int z, int projection)
{
	double		previous_x;
	double		previous_y;

	previous_x = *x;
	previous_y = *y;
	if (!projection)
	{
		*x = (previous_x - previous_y) * cos(0.523599) + 500;
		*y = -z + (previous_x + previous_y) * sin(0.523599) - 150;
	}
	else
	{
		*x = (previous_x - previous_y) * cos(0.523599 * 1.5) + 550;
		*y = -z + (previous_x + previous_y) * sin(0.523599 * 1.5) - 310;
	}
}

void		up_view(double *x, double *y, int z)
{
	double		previous_x;
	double		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599 * 1.5) + 500;
	*y = -z + (previous_x + previous_y) * sin(0.523599 * 1.5) - 150;
}

void		get_coord(t_fdf *fdf)
{
	t_coord		*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	coord->color = (int *)malloc(sizeof(int) * fdf->vert_count);
	fdf->coord = coord;
	read_colors(fdf);
}

int			get_array(t_fdf *fdf)
{
	int		**array;
	int		idx;
	int		fd;
	char	**splited;
	char	*line;

	if (!norminate(fdf))
		return (0);
	idx = -1;
	fd = open(fdf->file_name, O_RDONLY);
	if (fd == -1)
		ft_putendl("Error: file did not open\n");
	array = (int **)malloc(sizeof(int *) * fdf->count.y);
	while (get_next_line(fd, &line))
	{
		splited = ft_strsplit(line, ' ');
		array[++idx] = create_array(splited, fdf->count.x);
		clean_text(splited);
		free(line);
	}
	free(line);
	fdf->array_y_z = array;
	close(fd);
	return (1);
}

void		error_exit(int errnum)
{
	if (errnum == 1)
		ft_putendl("File error");
	else if (errnum == 2)
		ft_putendl("usage: ./fdf a_file_with_coordinates");
	exit(0);
}
