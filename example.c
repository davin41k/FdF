/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:19:43 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/27 22:52:15 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

void	draw_square(void *mlx_ptr, void *win_ptr)
{
	int x = 0;
	int y = 0;

	while (x++ < 100)
		mlx_pixel_put(mlx_ptr, win_ptr, 250 + x, 250, 0xFFFFFF);
	while (y++ < 100)
		mlx_pixel_put(mlx_ptr, win_ptr, 250 + x, 250 + y, 0xFFFFFF);
	while (x-- > 0)
		mlx_pixel_put(mlx_ptr, win_ptr, 250 + x, 250 + y, 0xFFFFFF);
	while (y-- > 0)
		mlx_pixel_put(mlx_ptr, win_ptr, 250 + x, 250 + y, 0xFFFFFF);
}

int		f1(int keycode, void *param)
{
	//write(1, "Hello world\n", 12);
	if (keycode == 53)
		exit(0);
	return (0);
}

int key_release(int keycode, void *param)
{
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

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_hook(win_ptr, 2, 0, f1, (void*)0);
	mlx_hook(win_ptr, 3, 0, key_release, (void*)0);
	mlx_hook(win_ptr, 17, 0, close1, (void*)0);
	draw_square(mlx_ptr, win_ptr);
	draw_line(mlx_ptr, win_ptr, 50, 50, 111, 170);
	mlx_loop(mlx_ptr);

	return (0);
}
