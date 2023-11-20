/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:54:09 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 16:41:14 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_camera(t_data *data, int x, int y)
{
	data->x_dir = x * 64 - PLANE_L * (data->input.map[y][x] == 'W') + PLANE_L
		* (data->input.map[y][x] == 'E');
	data->y_dir = y * 64 - PLANE_L * (data->input.map[y][x] == 'N') + PLANE_L
		* (data->input.map[y][x] == 'S');
	data->x_plane1 = data->x_dir - PLANE_L * (data->input.map[y][x] == 'N')
		+ PLANE_L * (data->input.map[y][x] == 'S');
	data->y_plane1 = data->y_dir - PLANE_L * (data->input.map[y][x] == 'W')
		+ PLANE_L * (data->input.map[y][x] == 'E');
	data->x_plane2 = data->x_dir + PLANE_L * (data->input.map[y][x] == 'N')
		- PLANE_L * (data->input.map[y][x] == 'S');
	data->y_plane2 = data->y_dir + PLANE_L * (data->input.map[y][x] == 'W')
		- PLANE_L * (data->input.map[y][x] == 'E');
	printf("x_plane1: %f\n", data->x_plane1);
	printf("y_plane1: %f\n", data->y_plane1);
	printf("x_plane2: %f\n", data->x_plane2);
	printf("y_plane2: %f\n", data->y_plane2);
}
static int	find_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->input.height)
	{
		x = -1;
		while (++x < data->input.width)
		{
			if (ft_contains("NSWE", data->input.map[y][x]))
			{
				if (data->player.player)
					return (1);
				data->player.player = data->input.map[y][x];
				data->player.x = x * 64;
				data->player.y = y * 64;
				set_camera(data, x, y);
			}
		}
	}
	return (!data->player.player);
}

static int	check_borders(t_input *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] == '0' || data->map[i][data->width - 1] == '0')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] == '0' || data->map[data->height - 1][i] == '0')
			return (1);
		i++;
	}
	return (0);
}

static int	validate_chars(t_input *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (!ft_contains("10 NSWE", data->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_walls(t_input *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->height - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (ft_contains("NSWE0", data->map[y][x]))
			{
				if (data->map[y][x + 1] == ' ' || data->map[y][x - 1] == ' '
					|| data->map[y + 1][x] == ' ' || data->map[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_valid_map(t_data *data)
{
	if (find_player(data))
		return (0);
	if (validate_chars(&data->input))
		return (0);
	if (check_borders(&data->input))
		return (0);
	if (check_walls(&data->input))
		return (0);
	return (1);
}
