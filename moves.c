/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 16:39:00 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_data *data)
{
	data->player.y -= 1 * SPEED;
	data->y_dir -= 1 * SPEED;
	data->y_plane1 -= 1 * SPEED;
	data->y_plane2 -= 1 * SPEED;
}

void	go_backward(t_data *data)
{
	data->player.y += 1 * SPEED;
	data->y_dir += 1 * SPEED;
	data->y_plane1 += 1 * SPEED;
	data->y_plane2 += 1 * SPEED;
}

void	rotate_vec(float *x, float *y, float *anchor_x, float *anchor_y)
{
	float	oldx;

	*x -= *anchor_x;
	*y -= *anchor_y;
	oldx = *x;
	*x = oldx * cos(ROTATE_SPEED) - *y * sin(ROTATE_SPEED);
	*y = oldx * sin(ROTATE_SPEED) + *y * cos(ROTATE_SPEED);
	*x += *anchor_x;
	*y += *anchor_y;
}
void	rotate_vec_back(float *x, float *y, float *anchor_x, float *anchor_y)
{
	float	oldx;

	*x -= *anchor_x;
	*y -= *anchor_y;
	oldx = *x;
	*x = oldx * cos(-ROTATE_SPEED) - *y * sin(-ROTATE_SPEED);
	*y = oldx * sin(-ROTATE_SPEED) + *y * cos(-ROTATE_SPEED);
	*x += *anchor_x;
	*y += *anchor_y;
}

void	turn_left(t_data *data)
{
	rotate_vec_back(&data->x_dir, &data->y_dir, &data->player.x, &data->player.y);
	rotate_vec_back(&data->x_plane1, &data->y_plane1, &data->player.x,
		&data->player.y);
	rotate_vec_back(&data->x_plane2, &data->y_plane2, &data->player.x,
		&data->player.y);
}

void	turn_right(t_data *data)
{
	rotate_vec(&data->x_dir, &data->y_dir, &data->player.x, &data->player.y);
	rotate_vec(&data->x_plane1, &data->y_plane1, &data->player.x,
		&data->player.y);
	rotate_vec(&data->x_plane2, &data->y_plane2, &data->player.x,
		&data->player.y);
}

void	go_left(t_data *data)
{
	data->player.x -= 1 * SPEED;
	data->x_dir -= 1 * SPEED;
	data->x_plane1 -= 1 * SPEED;
	data->x_plane2 -= 1 * SPEED;
}

void	go_right(t_data *data)
{
	data->player.x += 1 * SPEED;
	data->x_dir += 1 * SPEED;
	data->x_plane1 += 1 * SPEED;
	data->x_plane2 += 1 * SPEED;
}