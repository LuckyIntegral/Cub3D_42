/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:45:36 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 22:26:29 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_images(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->east = mlx_xpm_file_to_image(data->mlx_ptr, data->input.east, &x, &y);
	if (!data->east)
		return (1);
	data->west = mlx_xpm_file_to_image(data->mlx_ptr, data->input.west, &x, &y);
	if (!data->west)
		return (1);
	data->south = mlx_xpm_file_to_image(data->mlx_ptr, data->input.south, &x,
			&y);
	if (!data->south)
		return (1);
	data->north = mlx_xpm_file_to_image(data->mlx_ptr, data->input.north, &x,
			&y);
	if (!data->north)
		return (1);
	return (0);
}

void	init_structure(t_data *data)
{
	data->img = NULL;
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
	data->east = NULL;
	data->west = NULL;
	data->south = NULL;
	data->north = NULL;
	data->input.map = NULL;
	data->input.width = 0;
	data->input.height = 0;
	data->input.north = NULL;
	data->input.south = NULL;
	data->input.west = NULL;
	data->input.east = NULL;
	data->input.floor = 0;
	data->input.ceiling = 0;
	data->player.player = 0;
	data->player.x = 0;
	data->player.y = 0;
}
