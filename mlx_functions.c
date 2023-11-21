/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/21 17:45:09 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <mlx.h>

void	ft_new_image(t_data *data, int width, int height)
{
	data->img->reference = mlx_new_image(data->mlx_ptr, width, height);
	data->img->pixels = (int *)mlx_get_data_addr(data->img->reference,
			&data->img->bits_per_pixel, &data->img->line_size,
			&data->img->endian);
	data->img->bits_per_pixel /= 8;
}

void	bresenham(t_data *data, t_point p1, t_point p2, float length)
{
	float	ex;
	float	ey;
	float	max;
	int		index;

	ex = p2.x - p1.x;
	ey = p2.y - p1.y;
	max = fmax(fabs(ex), fabs(ey));
	ey /= max;
	ex /= max;
	p2.x += ex * length;
	p2.y += ey * length;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		index = WIDTH * (int)p1.y + (int)p1.x;
		if (p1.y < HEIGHT && index >= 0 && p1.y >= 0 && p1.x >= 0
			&& p1.x < WIDTH)
			data->img->pixels[index] = p1.color;
		if (data->input.map[(int)p1.y / IMAGE_SIZE][(int)p1.x
			/ IMAGE_SIZE] == '1')
		{
			printf("l %f\n", sqrt(pow(p1.y - p2.y, 2) + pow(p1.x - p2.x, 2)));
			break ;
		}
		p1.x += ex;
		p1.y += ey;
	}
}
void	do_rays(t_data *data, t_point dir, float length)
{
	t_point	p;
	float	del_x;
	float	del_y;
	int		i;

	i = -1;
	p.x = data->player.x;
	p.y = data->player.y;
	p.color = 0x5500FF00;
	del_x = (dir.x - data->player.x);
	del_y = (dir.y - data->player.y);
	dir.x = (del_x * cos(-0.78) - del_y * sin(-0.78)) + data->player.x;
	dir.y = (del_x * sin(-0.78) + del_y * cos(-0.78)) + data->player.y;
	while (++i < WIDTH)
	{
		bresenham(data, p, dir, length);
		del_x = (dir.x - data->player.x);
		del_y = (dir.y - data->player.y);
		dir.x = (del_x * cos(1.5708 / WIDTH) - del_y * sin(1.5708 / WIDTH))
			+ data->player.x;
		dir.y = (del_x * sin(1.5708 / WIDTH) + del_y * cos(1.5708 / WIDTH))
			+ data->player.y;
		i++;
	}
}
void	draw_cell(t_data *data, int x, int y, int color)
{
	const int	x1 = x + IMAGE_SIZE;
	const int	y1 = y + IMAGE_SIZE;

	printf("x: %d, y: %d, x1: %d, y1: %d\n", x, y, x1, y1);
	printf("color: %d\n", color);
	while (x < x1)
	{
		y = y1 - IMAGE_SIZE;
		while (y < y1)
		{
			data->img->pixels[WIDTH * (int)y + (int)x] = color;
			y++;
		}
		x++;
	}
}
int	display_handler(t_data *data)
{
	t_point	p1;

	p1.x = data->player.x;
	p1.y = data->player.y;
	p1.color = 0x0000FF;
	ft_new_image(data, WIDTH, HEIGHT);
	for (int y = 0; y < data->input.height; y++)
	{
		for (int x = 0; x < data->input.width; x++)
		{
			printf("x: %d, y: %d\n", x, y);
			printf("data->input.map[y][x]: %c\n", data->input.map[y][x]);
			if (data->input.map[y][x] == '0')
				draw_cell(data, x * IMAGE_SIZE, y * IMAGE_SIZE, 0x550000);
			else if (data->input.map[y][x] == '1')
				draw_cell(data, x * IMAGE_SIZE, y * IMAGE_SIZE, 0xFFFFFF);
		}
	}
	do_rays(data, data->dir, 400);
	/* bresenham(data, data->dir, p1, 1);
	bresenham(data, data->plane, data->plane2, 1);
	bresenham(data, p1, data->plane2, 400);
	bresenham(data, p1, data->plane, 400); */
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	return (0);
}

int	key_handler(int key, t_data *data)
{
	if (key == ESC)
		close_game(data);
	else if (key == W)
		go_forward(data);
	else if (key == A)
		go_left(data);
	else if (key == S)
		go_backward(data);
	else if (key == D)
		go_right(data);
	else if (key == XK_Left)
		turn_left(data);
	else if (key == XK_Right)
		turn_right(data);
	printf("player position {x: %f, y: %f}\n", data->player.x, data->player.y);
	return (0);
}