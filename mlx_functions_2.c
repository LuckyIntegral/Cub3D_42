/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:43:26 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/25 18:35:21 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <mlx.h>

void	draw_cell(t_data *data, int x, int y, int color)
{
	const int	x1 = x + MMAP_SIZE;
	const int	y1 = y + MMAP_SIZE;

	while (x < x1)
	{
		y = y1 - MMAP_SIZE;
		while (y < y1)
		{
			data->img->pixels[WIDTH * (int)y + (int)x] = color;
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = -MMAP_RADIUS;
	while (x <= MMAP_RADIUS)
	{
		y = -MMAP_RADIUS;
		while (y <= MMAP_RADIUS)
		{
			if (ft_abs(x) == MMAP_RADIUS || ft_abs(y) == MMAP_RADIUS)
				draw_cell(data, (x + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + x,
				(y + MMAP_RADIUS) * MMAP_SIZE + MMAP_RADIUS + y, MMAP_BORDER);
			y++;
		}
		x++;
	}
	// for (int y = 0; y < data->input.height; y++)
	// {
	// 	for (int x = 0; x < data->input.width; x++)
	// 	{
	// 		if (data->input.map[y][x] == '0')
	// 			draw_cell(data, x * MMAP_SIZE, y * MMAP_SIZE, 0x550000);
	// 		else if (data->input.map[y][x] == '1')
	// 			draw_cell(data, x * MMAP_SIZE, y *MMAP_SIZE, 0xFFFFFF);
	// 	}
	// }

}