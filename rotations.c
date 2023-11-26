/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:24:06 by dgutak            #+#    #+#             */
/*   Updated: 2023/11/26 15:24:36 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	rotate_vec_back(&data->dir.x, &data->dir.y, &data->player.x,
		&data->player.y);
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
