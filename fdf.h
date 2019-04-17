/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:50:50 by dshereme          #+#    #+#             */
/*   Updated: 2019/03/10 18:27:15 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H

# define FDF_H

# define WIN_HEIGHT 1080
# define WIN_WIDTH	1920
# define GET_NUM	0
# define INCREASE	1

#include <mlx.h>
#include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

typedef	struct s_graphics
{
	void		*win_ptr;
	void		*mlx_ptr;
}				t_graph;

typedef	struct	s_coord
{
	int			*x;
	int			*y;
	int			*z;
	int			*color;
}				t_coord;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef	struct	s_fdf
{
	char		*title;			//
	char		*file_name;		//INIT: fdf_init
	int			**array_y_z;	//INIT: get_array
	t_graph		*graph;		//INIT: fdf_init
	t_coord		*coord;
	int			vert_count;
	t_point		count;	//кол-во линий и символов INIT: norminate
	t_point		start_pos;
	t_point		save_start_pos;
	t_point		scale;	//WIN_.. * count of x/y
	t_point		delta;	//прирост за шаг	//INIT: fdf_coord_init
	t_point		start_delta;
}				t_fdf;

//norminate.c
int     norminate(t_fdf *fdf);
int		get_count_x (char *line);
int		get_count_y(int y);
void	show_array(t_fdf *fdf);
void	show_coord(t_fdf *fdf);

//read_figure.c
int		get_array(t_fdf *fdf);
int		*create_array(char **splitted, int size);

//initialization.c
void	fdf_init(t_fdf **fdf, char *file_name);
void	fdf_coord_init(t_fdf *fdf);
t_coord	*coord_init(t_fdf *fdf);
void	get_coord(t_fdf *fdf);

//dda.c
void	draw_line(t_fdf *fdf, t_point p_one, t_point p_two);
int		fdf_exit(int key, void *param);
void	sicle_draw(t_fdf *fdf);
void	draw_figure(t_fdf *fdf);

//hotkeys.c
int		hotkeys(int key, t_fdf *fdf);
void	figure_move(int key, t_fdf *fdf);
void	figure_scale(int key, t_fdf *fdf);
void	figure_restart(int key, t_fdf *fdf);
void	rotate (int key, t_fdf *fdf);


//rotate_figure.c
void	rotate_right(t_fdf *fdf);
void	draw_rotate_vert_lineas(t_fdf *fdf);


#endif