/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:43:26 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 14:29:02 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_cell(t_data *data, int x, int y, int color)
{
	const int	x1 = x + MMAP_SIZE;
	const int	y1 = y + MMAP_SIZE;

	while (x < x1)
	{
		y = y1 - MMAP_SIZE;
		while (y < y1)
		{
			data->img->pixels[WIDTH * y + x] = color;
			y++;
		}
		x++;
	}
}

static void	draw_border(t_data *data)
{
	int	x;
	int	y;

	x = -MMAP_RADIUS;
	while (x <= MMAP_RADIUS)
	{
		draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
			0, MMAP_BORDER);
		draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
			(MMAP_RADIUS * 2) * (MMAP_SIZE + 1), MMAP_BORDER);
		if (ft_abs(x) == MMAP_RADIUS)
		{
			y = -MMAP_RADIUS + 1;
			while (y <= MMAP_RADIUS - 1)
			{
				draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
					(y + MMAP_RADIUS) * MMAP_SIZE
					+ MMAP_RADIUS + y, MMAP_BORDER);
				y++;
			}
		}
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	const int	px = (int)(data->player.x / 1024.0);
	const int	py = (int)(data->player.y / 1024.0);
	int			x;
	int			y;

	draw_border(data);
	x = ft_tr(px < MMAP_RADIUS - 1, -px, -MMAP_RADIUS + 1);
	while (x <= MMAP_RADIUS - 1 && px + x < data->input.width)
	{
		y = ft_tr(py < MMAP_RADIUS - 1, -py, -MMAP_RADIUS + 1);
		while (y <= MMAP_RADIUS - 1 && py + y < data->input.height)
		{
			if (data->input.map[py + y][px + x] == '0')
				draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
					(y + MMAP_RADIUS) * MMAP_SIZE
					+ MMAP_RADIUS + y, MMAP_EMPTY);
			else if (data->input.map[py + y][px + x] == '1')
				draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
					(y + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + y, MMAP_WALL);
			y++;
		}
		x++;
	}
	draw_cell(data, (MMAP_RADIUS + 1) * MMAP_SIZE + 2,
		(MMAP_RADIUS + 1) * MMAP_SIZE + 2, MMAP_PLAYER);
}
