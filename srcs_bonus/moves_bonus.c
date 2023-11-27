/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 17:29:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	go_forward(t_data *data)
{
	const double	delta_x = (data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = (data->dir.y - data->player.y) / DIR_L;

	if (data->input.map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	go_backward(t_data *data)
{
	const double	delta_x = -(data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = -(data->dir.y - data->player.y) / DIR_L;

	if (data->input.map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	go_left(t_data *data)
{
	const double	delta_x = (data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = -(data->dir.x - data->player.x) / DIR_L;

	if (data->input.map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	go_right(t_data *data)
{
	const double	delta_x = -(data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = (data->dir.x - data->player.x) / DIR_L;

	if (data->input.map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
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
