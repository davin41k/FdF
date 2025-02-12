/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:34:15 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 17:24:25 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		norminate(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		ret;
	int		first_line;

	fd = open(fdf->file_name, O_RDONLY);
	first_line = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			error_exit(2);
		get_count_y(INCREASE);
		if (first_line == -1)
			first_line = get_count_x(line);
		if (!norme_norminatte(first_line, line, fd))
			return (0);
		free(line);
	}
	free(line);
	fdf->count.x = first_line;
	fdf->count.y = get_count_y(GET_NUM);
	close(fd);
	return (1);
}

int		norme_norminatte(int first_line, char *line, int fd)
{
	if (first_line != get_count_x(line) || first_line < 2)
	{
		free(line);
		close(fd);
		return (0);
	}
	return (1);
}

int		get_count_x(char *line)
{
	char	**splited;
	int		idx;
	int		count;

	count = 0;
	idx = -1;
	splited = ft_strsplit(line, ' ');
	while (splited[count])
		count++;
	clean_text(splited);
	return (count);
}

int		get_count_y(int y)
{
	static	int	count_y;

	if (y == GET_NUM)
		return (count_y);
	return (++count_y);
}
