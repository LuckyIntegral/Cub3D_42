/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 14:27:37 by dgutak           ###   ########.fr       */
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

void	bresenham(t_data *data, int x, int y)
{
	float	ex;
	float	ey;
	float	max;
	int		index;

	ex = data->player.x - x;
	ey = data->player.y - y;
	max = fmax(fabs(ex), fabs(ey));
	ey /= max;
	ex /= max;
	while ((int)(x - data->player.x) || (int)(y - data->player.y))
	{
		printf("x = %d, y = %d\n", (int)x, (int)y);
		index = WIDTH * (int)y + (int)x;
		if (y < HEIGHT && index >= 0 && y >= 0 && x >= 0
			&& x < WIDTH)
			data->img->pixels[index] = 0x222222;
		x += ex;	
		y += ey;
	}
	printf("let me ozut");
}
int	display_handler(t_data *data)
{
	ft_new_image(data, WIDTH, HEIGHT);
	bresenham(data, 100, 100);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->north,
		data->player.x, data->player.y);
	return (0);
}

int	key_handler(int key, t_data *data)
{
	if (key == ESC)
		close_game(data);
	else if (key == W || key == XK_Up)
		go_forward(data);
	else if (key == A || key == XK_Left)
		go_left(data);
	else if (key == S || key == XK_Down)
		go_backward(data);
	else if (key == D || key == XK_Right)
		go_right(data);
	printf("player position {x: %d, y: %d}\n", data->player.x, data->player.y);
	return (0);
}