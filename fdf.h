/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:53:27 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/28 18:25:23 by dshereme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
#include <unistd.h>
#include "./get_next_line/get_next_line.h"

typedef	struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_vertex
{
	t_point				crnt_pos;
	int					color;
	struct	s_point		*next;
}						t_vertex;

 typedef struct			s_figure
 {
	 int				**points;
	 int				start_position[2];
	 int				color;
	 int				x_len;
	 int				y_len;
	 int				step_len;
 }						t_figure;

void		draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
t_vertex	*new_vertex(void);
t_vertex	*get_vertices(char  *file_name);

int			y_count(char *file_name);
int			x_count(char *file_name);
t_figure	*new_figure(char *file_name);
void		show_coordinates(t_figure *figura);
int			**create_array(char *file_name);
void		fill_array(int **array, char *filename);
void		draw_figure(void *mlx_ptr, void *win_ptr, t_figure *figura);
