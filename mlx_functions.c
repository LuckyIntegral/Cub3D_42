/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 22:17:33 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	display_handler(t_data *data)
{
	for (int i = 0; i < HEIGHT; i += 64) {
		for (int j = 0; j < WIDTH; j += 64) {
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->west, j, i);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->north, data->player.x, data->player.y);
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