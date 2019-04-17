/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:50:50 by dshereme          #+#    #+#             */
/*   Updated: 2019/04/12 20:01:53 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define WIN_FHD_HEIGHT 1080
# define WIN_FHD_WIDTH	1920
# define WIN_HD_HEIGHT	720
# define WIN_HD_WIDTH	1280
# define SCROLL_UP		4
# define SCROLL_DOWN	5
# define GET_NUM		0
# define INCREASE		1
# define DECREASE		0
# define _USE_MATH_DEFINES

# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

typedef	struct	s_graphics
{
	void		*win_ptr;
	void		*mlx_ptr;
	int			help_info;
}				t_graph;

typedef	struct	s_coord
{
	int			*color;
}				t_coord;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef	struct	s_fdf
{
	char		*title;
	char		*file_name;
	int			win_height;
	int			win_width;
	int			**array_y_z;
	t_graph		*graph;
	t_coord		*coord;
	int			vert_count;
	t_point		count;
	t_point		start_pos;
	t_point		save_start_pos;
	t_point		scale;
	t_point		delta;
	t_point		start_delta;
	int			projection;
}				t_fdf;

int				norminate(t_fdf *fdf);
int				get_count_x (char *line);
int				get_count_y(int y);
void			show_array(t_fdf *fdf);
int				norme_norminatte(int first_line, char *line, int fd);

int				get_array(t_fdf *fdf);
int				*create_array(char **splitted, int size);
void			view_projections(double *x, double *y, int z, int projection);
void			up_view(double *x, double *y, int z);
void			fill_coolors(t_fdf *fdf, char *splitted, int idx);
void			read_colors(t_fdf *fdf);
void			error_exit(int errnum);
int				str_array_count(char **array);

void			fdf_init(t_fdf **fdf, char *file_name);
void			fdf_coord_init(t_fdf *fdf);
void			get_coord(t_fdf *fdf);

void			draw_line(t_fdf *fdf, t_point p_one, t_point p_two);
void			sicle_draw(t_fdf *fdf);
void			draw_figure(t_fdf *fdf);
void			do_projection(t_point *p_one, t_point *p_two, int projection);

int				hotkeys(int key, t_fdf *fdf);
int				hotkeys_one(int key, t_fdf *fdf);
void			figure_move(int key, t_fdf *fdf);
void			figure_scale(int key, t_fdf *fdf);
void			figure_restart(int key, t_fdf *fdf);
int				mouse_scroll(int key, int x, int y, t_fdf *fdf);

int				hex_to_decimal(char *str_num);
void			clean_text(char **splitted);
void			clean_all_memory(t_fdf *fdf);

void			clean_array_coord_and_graph(t_fdf *fdf);
void			resize_window(t_fdf *fdf);
void			change_projection(t_fdf *fdf, int projection);
int				fdf_exit(int key, void *param);
int				is_true_digit(char digit);
void			drow_text(t_fdf *fdf);

#endif
