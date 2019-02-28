/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:20:53 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/28 18:25:43 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		f1(int keycode, void *param)
{
	param = NULL;
	//write(1, "Hello world\n", 12);
	if (keycode == 53)
		exit(0);
	return (0);
}

int key_release(int keycode, void *param)
{
	param = NULL;
	if (keycode == 49)
		exit(0);
	return (0);
}

int close1(void *param)
{
	(void)param;
	exit(0);
	return (0);
}


int		main(int ac, char **av)
{
	t_figure    *figura;

	if (ac == 2)
	{
	figura = new_figure(av[1]);
	show_coordinates(figura);
	void	*mlx_ptr;
	void	*win_ptr;
	//int		i;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_hook(win_ptr, 2, 0, f1, (void*)0);
	mlx_hook(win_ptr, 3, 0, key_release, (void*)0);
	mlx_hook(win_ptr, 17, 0, close1, (void*)0);
	//draw_square(mlx_ptr, win_ptr);
	draw_line(mlx_ptr, win_ptr, 50, 50, 111, 170);
	draw_figure(mlx_ptr, win_ptr, figura);
	mlx_loop(mlx_ptr);
	}
	else
		printf("usage: ./fdf file_with_map");
}
