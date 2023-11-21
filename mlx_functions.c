/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/21 01:17:47 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
		p1.x += ex;
		p1.y += ey;
	}
}
void do_rays(t_data *data, t_point p1, t_point p2, float length)
{
	float	ex;
	float	ey;
	float	max;
	int		index;
	t_point p;

	ex = p2.x - p1.x;
	ey = p2.y - p1.y;
	max = fmax(fabs(ex), fabs(ey));
	ey /= max;
	ex /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		index = WIDTH * (int)p1.y + (int)p1.x;
		if (p1.y < HEIGHT && index >= 0 && p1.y >= 0 && p1.x >= 0
			&& p1.x < WIDTH)
		{
			p.x = data->player.x;
			p.y = data->player.y;
			p.color = 0x5500FF00;
			bresenham(data, p, p1, length);
		}
		p1.x += ex;
		p1.y += ey;
	}
}

int	display_handler(t_data *data)
{
	t_point	p1;

	p1.x = data->player.x;
	p1.y = data->player.y;
	p1.color = 0x0000FF;
	ft_new_image(data, WIDTH, HEIGHT);
	do_rays(data, data->plane2 , data->plane, 400);
	bresenham(data, data->dir, p1,1);
	bresenham(data, data->plane, data->plane2,1);
	bresenham(data, p1, data->plane2,400);
	bresenham(data, p1, data->plane,400);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);

	// just for tests
	for (int y = 0; y < data->input.height; y++) {
		for (int x = 0; x < data->input.width; x++) {
			switch (data->input.map[y][x]) {
				case (' '):
					break ;
				case ('1'):
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->west, x * IMAGE_SIZE, y * IMAGE_SIZE);
					break ;
				case ('0'):
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->south, x * IMAGE_SIZE, y * IMAGE_SIZE);
				default:
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->south, x * IMAGE_SIZE, y * IMAGE_SIZE);
					break ;
			}
		}
	}

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->north,
		data->player.x - (IMAGE_SIZE / 2.0f), data->player.y - (IMAGE_SIZE / 2.0f));
	return (0);
}

int	key_handler(int key, t_data *data)
{
	if (key == ESC)
		close_game(data);
	else if (key == W )
		go_forward(data);
	else if (key == A )
		go_left(data);
	else if (key == S )
		go_backward(data);
	else if (key == D )
		go_right(data);
	else if ( key == XK_Left)
		turn_left(data);
	else if ( key == XK_Right)
		turn_right(data);
	printf("player position {x: %f, y: %f}\n", data->player.x, data->player.y);
	return (0);
}