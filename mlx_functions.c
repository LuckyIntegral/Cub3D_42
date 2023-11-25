/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/25 20:29:24 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int	i;

	x = (int)(32 * 400 / dist);
	if (x > 400)
		x = 400;
	float ty_step = 32.0/(float)(2* x);
	float y = 0;
	float tx = (int)(p.x) % 32;
	float ty = (int)(p.y) % 32;
	i = 400 - x;
	while (i < 400 + x)
	{
		if ((int)tx == 0)
			data->img->pixels[WIDTH * i  + data->ray_num] = data->east_img->pixels[(int)y * 32 +(int)ty];
		else if ((int)ty == 0)
			data->img->pixels[WIDTH * i  + data->ray_num] = data->south_img->pixels[(int)y * 32 + 31 - (int)tx];
		else if ((int)tx == 31)
			data->img->pixels[WIDTH * i  + data->ray_num] = data->west_img->pixels[(int)y * 32 + 31 - (int)ty];
		else if ((int)ty == 31)
			data->img->pixels[WIDTH * i  + data->ray_num] = data->north_img->pixels[(int)y * 32 +(int)tx];
		i++;
		y += ty_step;
	}

}

void	bresenham(t_data *data, t_point p1, t_point p2, float length)
{
	float	ex;
	float	ey;
	float	max;
	// int		index;

	ex = p2.x - p1.x;
	ey = p2.y - p1.y;
	max = fmax(fabs(ex), fabs(ey));
	ey /= max;
	ex /= max;
	p2.x += ex * length;
	p2.y += ey * length;
	while (1)
	{
		// index = WIDTH * (int)(p1.y * MMAP_SIZE / IMAGE_SIZE) + (int)(p1.x * MMAP_SIZE / IMAGE_SIZE);
		// if (data->ray_num % 1 == 0)
		// 	if (p1.y < HEIGHT && index >= 0 && p1.y >= 0 && p1.x >= 0
		// 		&& p1.x < WIDTH )
		// 			data->img->pixels[index] += 0x00A500;
		if (IMAGE_SIZE * data->input.width > p1.x && IMAGE_SIZE
			* data->input.height > p1.y && data->input.map[(int)p1.y
			/ IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] != '0')
		{
			if ( data->input.map[(int)p1.y
			/ IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] == ' ')
				p1.x -= ex;
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
	while (++data->ray_num < WIDTH)
	{
		bresenham(data, p, dir, length);
		del_x = (dir.x - data->player.x);
		del_y = (dir.y - data->player.y);
		dir.x = (del_x * cos(FOV / WIDTH) - del_y * sin(FOV / WIDTH))
			+ data->player.x;
		dir.y = (del_x * sin(FOV / WIDTH) + del_y * cos(FOV / WIDTH))
			+ data->player.y;
		data->ray_angle += FOV / WIDTH;
	}
}

void draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			data->img->pixels[WIDTH * y + x] = data->input.ceiling;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
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
	do_rays(data, data->dir, 1);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 10);
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
