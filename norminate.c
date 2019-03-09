/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:34:15 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/09 18:27:58 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Норма + инициализация count.x && count.y
int     norminate(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		ret;
	int		first_line;

	fd = open(fdf->file_name, O_RDONLY);
	first_line = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		get_count_y(INCREASE);
		if (first_line == -1)
			first_line = get_count_x(line);
			if (first_line != get_count_x(line))
			{
				close(fd);
				return (0);
			}
		free(line);
	}
	fdf->count.x = first_line;
	fdf->count.y = get_count_y(GET_NUM);
	close(fd);
return (1);
}

int		get_count_x (char *line)
{
	char	**splited;
	int		idx;
	int		count;

	count = 0;
	idx = -1;
	splited = ft_strsplit(line, ' ');
	while (splited[count])
		count++;
	while (splited[++idx])
		free(splited[idx]);
	return (count);
}

//	При прогонке по матрице, с каждым новым у увеличиваем значение.
//	Если потом просто нужно его достать, то гетНам
int		get_count_y(int y)
{
	static	int	count_y;

	if (y == GET_NUM)
		return (count_y);
	return(++count_y);
}

void	show_array(t_fdf *fdf)
{
	int		**arr;
	int		i;
	int		j;

	i = -1;
	arr = fdf->array_y_z;
	while (++i < fdf->count.y)
	{
		j = -1;
		while (++j < fdf->count.x)
			printf("%3d", arr[i][j]);	
		printf("\n");
	}
}

void	show_coord(t_fdf *fdf)
{
	int		**arr;
	int		vert_count;

	vert_count = -1;
	arr = fdf->array_y_z;
	printf("X:\t%d\n\n", fdf->coord->x[0]);
	while (++vert_count < fdf->vert_count)
		{
			printf("[%5d%5d%5d%10d]", fdf->coord->x[vert_count], fdf->coord->y[vert_count],
			fdf->coord->z[vert_count], fdf->coord->color[vert_count]);
			//if (vert_count && (vert_count % (int)fdf->count.x -1) == 0)
				printf("\n");
		}
}
