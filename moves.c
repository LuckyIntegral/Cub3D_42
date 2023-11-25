/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/25 19:57:32 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_data *data)
{
	const float	delta_x = (data->dir.x - data->player.x) / DIR_L;
	const float	delta_y = (data->dir.y - data->player.y) / DIR_L;

	if (data->input.map[(int) data->player.y / IMAGE_SIZE]
			[(int)(data->player.x + SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
    	data->player.x += SPEED * delta_x;
    	data->dir.x += SPEED * delta_x;
    	data->plane.x += SPEED * delta_x;
    	data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y) / IMAGE_SIZE]
			[(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
    	data->plane.y += SPEED * delta_y;
    	data->plane2.y += SPEED * delta_y;
	}
}

void	go_backward(t_data *data)
{
	const float	delta_x = -(data->dir.x - data->player.x) / DIR_L;
	const float	delta_y = -(data->dir.y - data->player.y) / DIR_L;

	if (data->input.map[(int) data->player.y / IMAGE_SIZE]
			[(int)(data->player.x + SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
    	data->player.x += SPEED * delta_x;
    	data->dir.x += SPEED * delta_x;
    	data->plane.x += SPEED * delta_x;
    	data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y) / IMAGE_SIZE]
			[(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
    	data->plane.y += SPEED * delta_y;
    	data->plane2.y += SPEED * delta_y;
	}
}

void	rotate_vec(float *beg_x, float *beg_y, float *end_x, float *end_y)
{
	const float	del_x = (*beg_x - *end_x);
	const float	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(ROTATE_SPEED) - del_y * sin(ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(ROTATE_SPEED) + del_y * cos(ROTATE_SPEED)) + *end_y;
}
void	rotate_vec_back(float *beg_x, float *beg_y, float *end_x, float *end_y)
{
	const float	del_x = (*beg_x - *end_x);
	const float	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(-ROTATE_SPEED) - del_y * sin(-ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(-ROTATE_SPEED) + del_y * cos(-ROTATE_SPEED)) + *end_y;
}

void	turn_left(t_data *data)
{
	rotate_vec_back(&data->dir.x, &data->dir.y, &data->player.x, &data->player.y);
	rotate_vec_back(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vec_back(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}

void	turn_right(t_data *data)
{
	rotate_vec(&data->dir.x, &data->dir.y, &data->player.x, &data->player.y);
	rotate_vec(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vec(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}

void	go_left(t_data *data)
{
	const float	delta_x = (data->dir.y - data->player.y) / DIR_L;
	const float	delta_y = -(data->dir.x - data->player.x) / DIR_L;

	if (data->input.map[(int) data->player.y / IMAGE_SIZE]
			[(int)(data->player.x + SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
    	data->player.x += SPEED * delta_x;
    	data->dir.x += SPEED * delta_x;
    	data->plane.x += SPEED * delta_x;
    	data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y) / IMAGE_SIZE]
			[(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
    	data->plane.y += SPEED * delta_y;
    	data->plane2.y += SPEED * delta_y;
	}
}

void	go_right(t_data *data)
{
	const float	delta_x = -(data->dir.y - data->player.y) / DIR_L;
	const float	delta_y = (data->dir.x - data->player.x) / DIR_L;

	if (data->input.map[(int) data->player.y / IMAGE_SIZE]
			[(int)(data->player.x + SPEED * delta_x) / IMAGE_SIZE] == '0')
	{
    	data->player.x += SPEED * delta_x;
    	data->dir.x += SPEED * delta_x;
    	data->plane.x += SPEED * delta_x;
    	data->plane2.x += SPEED * delta_x;
	}
	if (data->input.map[(int)(data->player.y + SPEED * delta_y) / IMAGE_SIZE]
			[(int)(data->player.x / IMAGE_SIZE)] == '0')
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
    	data->plane.y += SPEED * delta_y;
    	data->plane2.y += SPEED * delta_y;
	}
}
