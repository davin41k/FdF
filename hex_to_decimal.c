/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:35:42 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 18:20:17 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_digit(char num)
{
	int		digit;

	if (num >= '0' && num <= '9')
		return (ft_atoi(&num));
	else
	{
		if (num == 'A' || num == 'a')
			digit = 10;
		else if (num == 'B' || num == 'b')
			digit = 11;
		else if (num == 'C' || num == 'c')
			digit = 12;
		else if (num == 'D' || num == 'd')
			digit = 13;
		else if (num == 'E' || num == 'e')
			digit = 14;
		else if (num == 'F' || num == 'f')
			digit = 15;
		else
			digit = 404;
	}
	return (digit);
}

int		hex_to_decimal(char *str_num)
{
	int		position;
	int		nb;
	int		digit;
	int		degree;

	position = ft_strlen(str_num);
	if (position < 4 || position > 9)
		return (-1);
	degree = 1;
	nb = 0;
	while (--position >= 2)
	{
		digit = get_digit(str_num[position]);
		if (digit == 404)
			return (-1);
		nb += digit * degree;
		degree *= 16;
	}
	return (nb);
}

void	clean_text(char **splitted)
{
	int		i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted);
}

void	clean_all_memory(t_fdf *fdf)
{
	int		idx;

	idx = -1;
	while (++idx < fdf->count.y)
		free(fdf->array_y_z[idx]);
	free(fdf->array_y_z);
	free(fdf->coord->color);
	free(fdf->coord);
	free(fdf->graph);
	free(fdf);
}

void	do_projection(t_point *p_one, t_point *p_two, int projection)
{
	if (projection == 0 || projection == 1)
	{
		view_projections(&p_one->x, &p_one->y, p_one->z, projection);
		view_projections(&p_two->x, &p_two->y, p_two->z, projection);
	}
}
