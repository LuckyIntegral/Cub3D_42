/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:54:09 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 22:31:51 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
				data->player.x = x * IMAGE_SIZE;
				data->player.y = y * IMAGE_SIZE;
				set_camera(data, x, y);
				data->input.map[y][x] = EMPTY;
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
		if (data->map[i][0] == EMPTY || data->map[i][data->width - 1] == EMPTY)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->width)
	{
		if (data->map[0][i] == EMPTY || data->map[data->height - 1][i] == EMPTY)
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
			if (!ft_contains("10 NSWED", data->map[y][x]))
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
			if (ft_contains("NSWE0D", data->map[y][x]))
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
