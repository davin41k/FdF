/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:25:03 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/27 22:52:07 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//заполняет массив координатами
void	fill_array(int **array, char *filename)
{
	int		fd;
	char	*line;
	char	**str_array;
	int		x;
	int 	y;

	fd = open(filename, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		str_array = ft_strsplit(line, ' ');
		if (!str_array)
			return ;
		while (str_array[++x])
			array[y][x] = ft_atoi(str_array[x]);
		y++;
		free(line);
		free(str_array);
	}
	if (*line)
		free(line);
	printf("FIELD\n");
	close(fd);
}

//выделяет память под  x/y
int		**create_array(char *file_name)
{
	int		fd;
	int		**coordinates;
	int		i;
	int		y;
	int		x;

	y = y_count(file_name);
	x = x_count(file_name);
	fd = open(file_name, O_RDONLY);
	coordinates = (int **)malloc(sizeof(int *) * y);
	i = -1;
	while (++i < y)
		coordinates[i] = (int *)malloc(sizeof(int) * x);
	close(fd);
	printf("CREATED\n");
	return (coordinates);
}

int		y_count(char *file_name)
{
	int				fd;
	static	int		count;
	char	*line;
	
	if (count)
		return (count);
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	return (-1);
	while (get_next_line(fd, &line))
	{
		//printf("YYCC\n");
		if (line != NULL)
			free(line);
		count++;
	}
	close(fd);
	return (count);
}

int		x_count(char *file_name)
{
	int				fd;
	static	int		count;
	char			*line;
	char			**split;

	if (count)
		return (count);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	split = ft_strsplit(line, ' ');
	while (*split)
	{
		//printf("XXCC\n");
		free(*split);
		count++;
		split++;
	}
	//free(split);
	free(line);
//	close(fd);
	return (count);
}
