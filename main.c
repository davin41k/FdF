/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:22:20 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/07 20:05:17 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int ac, char **av)
{
//   int      fd;
	t_fdf	*fdf;
	// int		**arr;
	// int		i;
	// int		j;

	// i = j = -1;
	fdf_init(&fdf, av[1]);
	get_array(fdf);
	fdf_coord_init(fdf);
	ac = 0;
	//printf("%d\n", norminate(fdf));
	// printf("X:\t%d\n", fdf->count.x);
	// printf("Y:\t%d\n", fdf->count.y);
//	arr = fdf->array_y_z;
	sicle_draw(fdf);
	// while (++i < fdf->count.y)
	// {
	// 	j = -1;
	// 	while (++j < fdf->count.x)
	// 	{
	// 		printf("X:\t%d\tY:\t%d\tZ:\t%d\n", j, i, arr[i][j]);
	// 	}
	// }
	//system("leaks fdf");
	return (0);
}
