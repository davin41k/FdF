/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:34:15 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/06 20:57:38 by dshereme         ###   ########.fr       */
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
	printf("fd  %d\n", fd);
	first_line = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		get_count_y(INCREASE);
		if (first_line == -1)
			first_line = get_count_x(line);
			if (first_line != get_count_x(line))
			{
				return (0);
				close(fd);
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
