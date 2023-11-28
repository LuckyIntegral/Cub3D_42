/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:07:40 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 20:21:12 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	rotate_vec_small_rotation(double *beg_x, double *beg_y,
		double *end_x, double *end_y)
{
	const double	del_x = (*beg_x - *end_x);
	const double	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(MOUSE_ROTATE_SPEED)
			- del_y * sin(MOUSE_ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(MOUSE_ROTATE_SPEED)
			+ del_y * cos(MOUSE_ROTATE_SPEED)) + *end_y;
}

static void	rotate_vec_back_small_rotation(double *beg_x, double *beg_y,
		double *end_x, double *end_y)
{
	const double	del_x = (*beg_x - *end_x);
	const double	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(-MOUSE_ROTATE_SPEED)
			- del_y * sin(-MOUSE_ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(-MOUSE_ROTATE_SPEED)
			+ del_y * cos(-MOUSE_ROTATE_SPEED)) + *end_y;
}

static void	turn_left_small_rotation(t_data *data)
{
	rotate_vec_back_small_rotation(&data->dir.x, &data->dir.y,
		&data->player.x, &data->player.y);
	rotate_vec_back_small_rotation(&data->plane.x, &data->plane.y,
		&data->player.x, &data->player.y);
	rotate_vec_back_small_rotation(&data->plane2.x, &data->plane2.y,
		&data->player.x, &data->player.y);
}

static void	turn_right_small_rotation(t_data *data)
{
	rotate_vec_small_rotation(&data->dir.x, &data->dir.y,
		&data->player.x, &data->player.y);
	rotate_vec_small_rotation(&data->plane.x, &data->plane.y,
		&data->player.x, &data->player.y);
	rotate_vec_small_rotation(&data->plane2.x, &data->plane2.y,
		&data->player.x, &data->player.y);
}

void	bound_mouse(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(data->mlx_ptr, data->mlx_window, &x, &y);
	if (x < WIDTH / 2)
	{
		turn_left_small_rotation(data);
		mlx_mouse_move(data->mlx_ptr, data->mlx_window, WIDTH / 2, HEIGHT / 2);
	}
	if (x > WIDTH / 2)
	{
		turn_right_small_rotation(data);
		mlx_mouse_move(data->mlx_ptr, data->mlx_window, WIDTH / 2, HEIGHT / 2);
	}
}
