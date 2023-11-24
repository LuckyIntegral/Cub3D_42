/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/24 17:46:05 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <math.h>
#include <mlx.h>
#include <time.h>

void	ft_new_image(t_data *data, int width, int height)
{
	data->img->reference = mlx_new_image(data->mlx_ptr, width, height);
	data->img->pixels = (int *)mlx_get_data_addr(data->img->reference,
			&data->img->bits_per_pixel, &data->img->line_size,
			&data->img->endian);
	data->img->bits_per_pixel /= 8;
}
void	draw_view(t_data *data, float dist, t_point p)
{
	int	x;
	int	y;
	int	i;

	x = (int)(32 * 400 / dist);
	if (x > 300)
		x = 300;
	y = 400 + x;
	i = 400 - x;
	while (i < y)
	{
		data->img->pixels[WIDTH * i + 700 + data->ray_num] = data->east_img->pixels[32 * (i - (400 - x)) + ((int)p.x % 32)];
		i++;
	}
	
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
	while (1)
	{
		index = WIDTH * (int)p1.y + (int)p1.x;
		if (data->ray_num % 1 == 0)
			if (p1.y < HEIGHT && index >= 0 && p1.y >= 0 && p1.x >= 0
				&& p1.x < WIDTH)
					data->img->pixels[index] += 0x00A500;
		if (IMAGE_SIZE * data->input.width > p1.x && IMAGE_SIZE
			* data->input.height > p1.y && data->input.map[(int)p1.y
			/ IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] == '1')
		{
			draw_view(data, sqrt(pow(data->player.y - p1.y, 2)
					+ pow(data->player.x - p1.x, 2))* cos(fabs(data->ray_angle)), p1);
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

	data->ray_num = -1;
	p.x = data->player.x;
	p.y = data->player.y;
	p.color = 0x5500FF00;
	del_x = (dir.x - data->player.x);
	del_y = (dir.y - data->player.y);
	dir.x = (del_x * cos(-FOV/2) - del_y * sin(-FOV/2)) + data->player.x;
	dir.y = (del_x * sin(-FOV/2) + del_y * cos(-FOV/2)) + data->player.y;
	data->ray_angle = -FOV/2;
	while (++data->ray_num < 700)
	{
		bresenham(data, p, dir, length);
		del_x = (dir.x - data->player.x);
		del_y = (dir.y - data->player.y);
		dir.x = (del_x * cos(FOV / 700) - del_y * sin(FOV / 700))
			+ data->player.x;
		dir.y = (del_x * sin(FOV / 700) + del_y * cos(FOV / 700))
			+ data->player.y;
		data->ray_angle += FOV / 700;
	}
}
void	draw_cell(t_data *data, int x, int y, int color)
{
	const int	x1 = x + IMAGE_SIZE;
	const int	y1 = y + IMAGE_SIZE;

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
void draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 700;
	while (x < 1400)
	{
		y = 100;
		while (y < HEIGHT / 2)
		{
			data->img->pixels[WIDTH * y + x] = data->input.ceiling;
			y++;
		}
		x++;
	}
	x = 700;
	while (x < 1400)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT - 100)
		{
			data->img->pixels[WIDTH * y + x] = data->input.floor;
			y++;
		}
		x++;
	}	
}

int	display_handler(t_data *data)
{
	clock_t start_time, end_time;
	start_time = clock();
	
	ft_new_image(data, WIDTH, HEIGHT);
	draw_background(data);
	for (int y = 0; y < data->input.height; y++)
	{
		for (int x = 0; x < data->input.width; x++)
		{
			if (data->input.map[y][x] == '0')
				draw_cell(data, x * IMAGE_SIZE, y * IMAGE_SIZE, 0x550000);
			else if (data->input.map[y][x] == '1')
				draw_cell(data, x * IMAGE_SIZE, y * IMAGE_SIZE, 0xFFFFFF);
		}
	}
	do_rays(data, data->dir, 1);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 10);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->east_img->reference, 0, 10);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	end_time = clock();
	double frame_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	data->total_time += frame_time;
	data->frame_count++;
	data->fps = data->frame_count / data->total_time;
	if (data->total_time > 0.5)
	{
		for (int x = 0; x < 20; x++)
			for (int y = 0; y < 10; y++)
				mlx_pixel_put(data->mlx_ptr, data->mlx_window, x, y, 0x000000);
		mlx_string_put(data->mlx_ptr, data->mlx_window, 1, 10, 0x00FF00, ft_itoa(data->fps));
		data->frame_count = 0;
		data->total_time = 0.0;
		
	}
	
		
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
	return (0);
}
