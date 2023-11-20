/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 15:18:37 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_data *data)
{
	data->player.y -= 1 * SPEED;
	data->y_dir -= 1 * SPEED;
}

void	go_backward(t_data *data)
{
	data->player.y += 1 * SPEED;
	data->y_dir += 1 * SPEED;
}

void	turn_left(t_data *data)
{
	float	olddirx;

	data->x_dir -= data->player.x;
	data->y_dir -= data->player.y;
	olddirx = data->x_dir;
	data->x_dir = olddirx * cos(-ROTATE_SPEED) - data->y_dir
		* sin(-ROTATE_SPEED);
	data->y_dir = olddirx * sin(-ROTATE_SPEED) + data->y_dir
		* cos(-ROTATE_SPEED);
	data->x_dir += data->player.x;
	data->y_dir += data->player.y;
}

void	turn_right(t_data *data)
{
	float	olddirx;

	data->x_dir -= data->player.x;
	data->y_dir -= data->player.y;
	olddirx = data->x_dir;
	data->x_dir = olddirx * cos(ROTATE_SPEED) - data->y_dir
		* sin(ROTATE_SPEED);
	data->y_dir = olddirx * sin(ROTATE_SPEED) + data->y_dir
		* cos(ROTATE_SPEED);
	data->x_dir += data->player.x;
	data->y_dir += data->player.y;
}

void	go_left(t_data *data)
{
	data->player.x -= 1 * SPEED;
	data->x_dir -= 1 * SPEED;
}

void	go_right(t_data *data)
{
	data->player.x += 1 * SPEED;
	data->x_dir += 1 * SPEED;
}