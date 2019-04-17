/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figure_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:37:17 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 18:22:36 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_true_digit(char digit)
{
	int		re;

	re = 0;
	if (ft_isdigit(digit) || digit == ',')
		re = 1;
	return (re);
}

int		check_atoi(const char *str)
{
	int						sign;
	unsigned long int		result;

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	while ((*str == ' ') || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_exit(1);
		result = result * 10 + *str - '0';
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)result * sign);
}

int		*create_array(char **splitted, int size)
{
	int		*array;
	int		idx;
	int		i;
	char	**str;

	idx = -1;
	i = -1;
	array = (int *)malloc(sizeof(int) * size);
	while (*splitted)
	{
		str = ft_strsplit(*splitted, ',');
		array[++idx] = check_atoi(*str);
		clean_text(str);
		splitted++;
	}
	return (array);
}

void	read_colors(t_fdf *fdf)
{
	int		fd;
	int		idx;
	char	**splitted;
	char	*line;
	char	**start_splitted;

	idx = -1;
	fd = open(fdf->file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		splitted = ft_strsplit(line, ' ');
		start_splitted = splitted;
		while (*splitted)
		{
			fill_coolors(fdf, *splitted, ++idx);
			splitted++;
		}
		clean_text(start_splitted);
		free(line);
	}
	free(line);
	close(fd);
}

void	fill_coolors(t_fdf *fdf, char *splitted, int idx)
{
	char		**new_splitt;

	if (ft_strchr(splitted, ','))
	{
		new_splitt = ft_strsplit(splitted, ',');
		if (str_array_count(new_splitt) != 2)
		{
			clean_text(new_splitt);
			error_exit(1);
		}
		else
		{
			fdf->coord->color[idx] = hex_to_decimal(new_splitt[1]);
			clean_text(new_splitt);
		}
		if (fdf->coord->color[idx] == -1)
			error_exit(1);
	}
	else
		fdf->coord->color[idx] = 0xFFFFFF;
}
