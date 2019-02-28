/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:40:23 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/28 12:58:26 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_figure	*new_figure(char *file_name)
{
	t_figure	*figura;
	int			**coordinates;

	if(!(figura = (t_figure *)malloc(sizeof(t_figure))))
		return (NULL);
		printf("FIGURA\n");
	coordinates = create_array(file_name);
		printf("COORD\n");
	fill_array(coordinates, file_name);
		printf("FIIL_ARRAY\n");
	figura->color = 0xFFFFFF;
	figura->points = coordinates;
	figura->x_len = x_count(file_name);
	figura->y_len = y_count(file_name);
	figura->start_position[0] = 150;
	figura->start_position[1] = 150;
	figura->step_len = 10;
	figura->points = coordinates;
	return (figura);	 
}

void		show_coordinates(t_figure *figura)
{
	int		i;
	int		j;

	i = -1;
	while (++i < figura->y_len)
	{
		j = -1;
		while (++j < figura->x_len)
			printf("%2d ", figura->points[i][j]);
		printf("\n");
	}
}