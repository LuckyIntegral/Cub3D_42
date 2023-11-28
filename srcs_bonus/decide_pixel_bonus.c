/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_pixel_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:36:14 by dgutak            #+#    #+#             */
/*   Updated: 2023/11/28 15:36:19 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_new_image(t_data *data, int width, int height)
{
	data->img->reference = mlx_new_image(data->mlx_ptr, width, height);
	data->img->pixels = (int *)mlx_get_data_addr(data->img->reference,
			&data->img->bits_per_pixel, &data->img->line_size,
			&data->img->endian);
	data->img->bits_per_pixel /= 8;
}

void	decide_pixel4(t_data *data, t_point p, int i, double y)
{
	double	tx;
	double	ty;

	tx = (int)(p.x) % IMAGE_SIZE;
	ty = (int)(p.y) % IMAGE_SIZE;
	if ((int)ty == IMAGE_SIZE - 1)
	{
		if (data->input.map[(int)p.y / IMAGE_SIZE][(int)p.x
			/ IMAGE_SIZE] == 'D')
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->door_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)tx];
		else
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->north_img->pixels[(int)y * IMAGE_SIZE
				+ (int)tx];
	}
}

void	decide_pixel3(t_data *data, t_point p, int i, double y)
{
	double	tx;
	double	ty;

	tx = (int)(p.x) % IMAGE_SIZE;
	ty = (int)(p.y) % IMAGE_SIZE;
	if ((int)tx == IMAGE_SIZE - 1)
	{
		if (data->input.map[(int)p.y / IMAGE_SIZE][(int)p.x
			/ IMAGE_SIZE] == 'D')
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->door_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)ty];
		else
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->west_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)ty];
		return ;
	}
	decide_pixel4(data, p, i, y);
}

void	decide_pixel2(t_data *data, t_point p, int i, double y)
{
	double	tx;
	double	ty;

	tx = (int)(p.x) % IMAGE_SIZE;
	ty = (int)(p.y) % IMAGE_SIZE;
	if ((int)ty == 0)
	{
		if (data->input.map[(int)p.y / IMAGE_SIZE][(int)p.x
			/ IMAGE_SIZE] == 'D')
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->door_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)tx];
		else
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->south_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)tx];
		return ;
	}
	decide_pixel3(data, p, i, y);
}

void	decide_pixel(t_data *data, t_point p, int i, double y)
{
	double	tx;
	double	ty;

	tx = (int)(p.x) % IMAGE_SIZE;
	ty = (int)(p.y) % IMAGE_SIZE;
	if ((int)tx == 0)
	{
		if (data->input.map[(int)p.y / IMAGE_SIZE][(int)p.x
			/ IMAGE_SIZE] == 'D')
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->door_img->pixels[(int)y * IMAGE_SIZE
				+ (int)ty];
		else
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->east_img->pixels[(int)y * IMAGE_SIZE
				+ (int)ty];
		return ;
	}
	decide_pixel2(data, p, i, y);
}
