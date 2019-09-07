/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:03:01 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/05 17:00:33 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_map
{
	int			height;
	int			width;
}				t_map;

typedef struct s_dot
{
	int			x;
	int			y;
	int			z;
	int		color;
}				t_dot;

typedef struct s_glob
{
	void *mlx_ptr;
	void *win_ptr;

	t_map map;
	t_dot *dot;
}				t_glob;

void ft_reader(char **str, t_glob *global);
int	 ft_width(char *line);
void ft_mlxer();

#endif