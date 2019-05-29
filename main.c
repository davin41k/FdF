/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:22:20 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/13 21:09:11 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		fdf_init(&fdf, av[1]);
		if (!get_array(fdf))
		{
			ft_putendl("error: file with coordinates is not in norme");
			exit(0);
		}
		fdf_coord_init(fdf);
		fdf->projection = 0;
		ac = 0;
		sicle_draw(fdf);
		clean_all_memory(fdf);
	}
	else
		error_exit(2);
	return (0);
}
