/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:45:36 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 16:14:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	init_images2(t_data *data, int *x, int *y)
{
	data->south_img->reference = mlx_xpm_file_to_image(data->mlx_ptr,
			data->input.south, x, y);
	if (!data->south_img->reference || *x != IMAGE_SIZE || *y != IMAGE_SIZE)
		return (1);
	data->south_img->pixels
		= (int *)mlx_get_data_addr(data->south_img->reference,
			&data->south_img->bits_per_pixel, &data->south_img->line_size,
			&data->south_img->endian);
	data->west_img->reference = mlx_xpm_file_to_image(data->mlx_ptr,
			data->input.west, x, y);
	if (!data->west_img->reference || *x != IMAGE_SIZE || *y != IMAGE_SIZE)
		return (1);
	data->west_img->pixels = (int *)mlx_get_data_addr(data->west_img->reference,
			&data->west_img->bits_per_pixel, &data->west_img->line_size,
			&data->west_img->endian);
	return (0);
}

int	init_images(t_data *data)
{
	int	x;
	int	y;

	x = IMAGE_SIZE;
	y = IMAGE_SIZE;
	data->north_img->reference = mlx_xpm_file_to_image(data->mlx_ptr,
			data->input.north, &x, &y);
	if (!data->north_img->reference || x != IMAGE_SIZE || y != IMAGE_SIZE)
		return (1);
	data->north_img->pixels
		= (int *)mlx_get_data_addr(data->north_img->reference,
			&data->north_img->bits_per_pixel, &data->north_img->line_size,
			&data->north_img->endian);
	data->east_img->reference = mlx_xpm_file_to_image(data->mlx_ptr,
			data->input.east, &x, &y);
	if (!data->east_img->reference || x != IMAGE_SIZE || y != IMAGE_SIZE)
		return (1);
	data->east_img->pixels = (int *)mlx_get_data_addr(data->east_img->reference,
			&data->east_img->bits_per_pixel, &data->east_img->line_size,
			&data->east_img->endian);
	if (init_images2(data, &x, &y))
		return (1);
	return (0);
}

static void	init_structure_helper(t_data *data)
{
	data->total_time = 0;
	data->frame_count = 0;
	data->fps = 0;
	data->ray_num = 0;
	data->ray_angle = 0;
	data->ty_step = 0;
	data->start_time = 0;
	data->end_time = 0;
}

void	init_structure(t_data *data)
{
	data->img = NULL;
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
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
	data->fps = 0;
	data->north_img = NULL;
	data->south_img = NULL;
	data->west_img = NULL;
	data->east_img = NULL;
	init_structure_helper(data);
}
