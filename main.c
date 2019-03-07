/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:22:20 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/07 21:31:03 by dshereme         ###   ########.fr       */
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
	if (!get_array(fdf))
	{
		ft_putendl("error: file with coordinates is not in norme");
		return (0);
	}
	//show_array(fdf);
	fdf_coord_init(fdf);
	ac = 0;
	sicle_draw(fdf);
	//system("leaks fdf");
	return (0);
}
