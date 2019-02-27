/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshereme <dshereme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:53:27 by dshereme          #+#    #+#             */
/*   Updated: 2019/02/26 13:23:36 by dshereme         ###   ########.fr       */
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

// typedef struct			s_figure
// {

// }

void		draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
t_vertex	*new_vertex(void);
char		**get_coordinates(int fd);
t_vertex	*get_vertices(char  *file_name);
