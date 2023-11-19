/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:54:09 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 16:29:03 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_player(t_input *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (ft_contains("NSWE", data->map[y][x]))
			{
				if (data->player.player)
					return (1);
				data->player.player = data->map[y][x];
				data->player.x = x;
				data->player.y = y;
			}
			x++;
		}
		y++;
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
	int		x;
	int		y;

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
	int		x;
	int		y;

	y = 1;
	while (y < data->height - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (ft_contains("NSWE0", data->map[y][x]))
			{
				if (data->map[y][x + 1] == ' ' || data->map[y][x -1] == ' '
					|| data->map[y + 1][x] == ' ' || data->map[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_valid_map(t_input *data)
{
	if (find_player(data))
		return (0);
	if (validate_chars(data))
		return (0);
	if (check_borders(data))
		return (0);
	if (check_walls(data))
		return (0);
	return (1);
}
