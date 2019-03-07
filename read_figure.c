/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:46:02 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/07 18:41:53 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//  чтение и запись массива в структуру. Если по нормпе ок - запись.
//  return 1 если все записало

int		get_array(t_fdf *fdf)
{
	int		**array;
	int		idx;
	int		fd;
	char	**splited;
	char	*line;

	if (!norminate(fdf)) // инициализация count.x/y
		return (0);
	idx = -1;
	fd = open (fdf->file_name, O_RDONLY);
	array = (int **)malloc(sizeof(int *) * fdf->count.y);
	// while (array[++idx])
	// 	array[idx] = (int *)malloc(sizeof(int) * fdf->count.x);

	while (get_next_line(fd, &line))
	{
		splited = ft_strsplit(line, ' ');
		array[++idx] = create_array(splited, fdf->count.x);
	}
	fdf->array_y_z = array;
	return (1);
}

int		*create_array(char **splitted, int size)
{
	int		*array;
	int		idx;

	idx = -1;
	array = (int *)malloc(sizeof(int) * size);
	while (*splitted)
	{
		array[++idx] = ft_atoi(*splitted);
		splitted++;
	}
	return (array);
}

// char	**read_str_coord(t_fdf *fdf)
// {
// 	char	**str;
// 	char	*line;
// 	int		fd; 
// 	//str = ft_strsplit()
// 	fd = open(fdf->file_name, O_RDONLY);
// 	get_next_line(fd, &line);
// 	fdf->count.x = get_count_x(line);
// 	get_count_y(INCREASE);
// 	while (get_next_line(fd, &line))
// 	{
// 		//где-то в этом файле читать координаты в массив
// 	}
// }
