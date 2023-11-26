/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/26 20:12:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	set_camera(t_data *data, int x, int y)
{
	data->dir.x = x * IMAGE_SIZE - DIR_L * (data->input.map[y][x] == 'W')
		+ DIR_L * (data->input.map[y][x] == 'E');
	data->dir.y = y * IMAGE_SIZE - DIR_L * (data->input.map[y][x] == 'N')
		+ DIR_L * (data->input.map[y][x] == 'S');
	data->dir.color = 0xFF0000;
	data->plane.color = 0xFFFF00;
}

void	ft_new_image(t_data *data, int width, int height)
{
	data->img->reference = mlx_new_image(data->mlx_ptr, width, height);
	data->img->pixels = (int *)mlx_get_data_addr(data->img->reference,
			&data->img->bits_per_pixel, &data->img->line_size,
			&data->img->endian);
	data->img->bits_per_pixel /= 8;
}

void	draw_background(t_data *data)
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
