/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:59:49 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/09/07 13:16:29 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}
int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_dot current, t_dot start, t_dot end, t_dot delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

static void iso (t_glob *glb)
{
	int i;

	i = 0;
	while (i < glb->map.width * glb->map.height)
	{
		glb->dot[i].x = (glb->dot[i].x - glb->dot[i].y) * cos(0.543599) + (500/2);
		glb->dot[i].y = (glb->dot[i].x + glb->dot[i].y) * sin(0.523599) -(glb->dot[i].z * 8);
		i++; 
	}
}

void	bresenham(void *mlx_ptr, void *win_ptr, t_dot dot1, t_dot dot2, t_glob *global)
{
	t_dot cur;
	t_dot delta;
	t_dot sign;
	delta.x = abs(dot2.x - dot1.x);
	delta.y = abs(dot2.y - dot1.y);
	sign.x = dot1.x < dot2.x ? 1 : -1;
	sign.y = dot1.y < dot2.y ? 1 : -1;
	int error = delta.x - delta.y;
	// int color;
	cur = dot1;
	while (cur.x != dot2.x || cur.y != dot2.y)
	{
	mlx_pixel_put(mlx_ptr, win_ptr, cur.x, cur.y, get_color(cur, dot1, dot2, delta));
      	int error2 = error * 2;

       	if (error2 > -delta.y)
       	{
        	error -= delta.y;
			cur.x += sign.x;
           	//dot1.x += signX;
    	}
        error += (error2 < delta.x ? delta.x : 0);
		cur.y += (error2 < delta.x ? sign.y : 0);
        //dot1.y += signY;
	}
}

void ft_draw(void *mlx_ptr, void *win_ptr, t_glob *global)
{
	int x;
	int y;

	y = 0;
	while(y < global->map.height)
	{
		x = 0;
		while (x < global->map.width)
		{
			if (x + 1 < global->map.width)
				bresenham(mlx_ptr, win_ptr, global->dot[y * global->map.width + x], global->dot[y * global->map.width + x + 1], global);
			if (y + 1 < global->map.height)
			 	bresenham(mlx_ptr, win_ptr, global->dot[y * global->map.width + x], global->dot[(y + 1) * global->map.width + x], global);
			x++;
		}
		y++;
	}
}

int deal_key(int key, void *param)
{
	t_glob *glbl;
	int i = 0;

	glbl = param;
	if (key == 53)
		exit(0);
	if (key == 34)
	{
		mlx_clear_window(glbl->mlx_ptr, glbl->win_ptr);
		iso(glbl);
		ft_draw(glbl->mlx_ptr, glbl->win_ptr, glbl);
	}
	return (0);
}

int main(int ac, char **av)
{
	int fd;
	char *line;
	t_glob *glbl;
	char **str;
	int i = 0;
	int j;
	int width;
	int height = 0;

	if (!(glbl = malloc(sizeof(t_glob))))
		return (0);
	glbl->map.width = 0;
	glbl->map.height = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		width = 0;
		str = ft_strsplit(line, ' ');
		while (str[width])
			width++;
		height++;
		free(line);
	}
	glbl->map.height = height;
	glbl->map.width = width;
	glbl->dot = malloc(sizeof(t_dot) * (glbl->map.height * glbl->map.width));
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		str = ft_strsplit(line, 32);
		while (str[j])
		{
			glbl->dot[i].x = j % glbl->map.width * 50 + 280;
			glbl->dot[i].y = i / glbl->map.width * 50 + 180;
			glbl->dot[i].z = ft_atoi(str[j]);
			if (glbl->dot[i].z == 0)
				glbl->dot[i].color = 0x191970;
			if (glbl->dot[i].z <= 5)
				glbl->dot[i].color = 0xE0FFFF;
			else
				glbl->dot[i].color = 0xFF00FF;
			j++;
			i++;
		}
		if (j != glbl->map.width)
		{
			write(1, "Jhonny, your map is shit\n", 27);
			return (0);
		}
		free(str);
		free(line);
	}
	glbl->mlx_ptr = mlx_init();
	glbl->win_ptr = mlx_new_window(glbl->mlx_ptr, 1400, 1400, "Jesus Christ");
	//iso(glbl);
	ft_draw(glbl->mlx_ptr, glbl->win_ptr, glbl);
	mlx_key_hook(glbl->win_ptr, (void*)deal_key, (void*)glbl);
	mlx_loop(glbl->mlx_ptr);
	return (0);
}
