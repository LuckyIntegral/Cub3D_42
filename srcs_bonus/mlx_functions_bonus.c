/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 16:23:48 by vfrants          ###   ########.fr       */
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

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			data->img->pixels[WIDTH * y + x] = data->input.ceiling;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			data->img->pixels[WIDTH * y + x] = data->input.floor;
			y++;
		}
		x++;
	}
}

static void	ft_itoa_insert(int n, char *str)
{
	char	temp;
	int		j;
	int		i;

	j = 0;
	if (n == 0)
		str[j++] = '0';
	while (n > 0)
	{
		str[j++] = n % 10 + '0';
		n /= 10;
	}
	i = 0;
	j--;
	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}

void	print_fps(t_data *data)
{
	double	frame_time;
	char	str[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		i;

	data->end_time = clock();
	frame_time = ((double)(data->end_time - data->start_time)) / CLOCKS_PER_SEC;
	data->total_time += frame_time;
	data->frame_count++;
	data->fps = data->frame_count / data->total_time;
	ft_itoa_insert(data->fps, str);
	i = -1;
	mlx_string_put(data->mlx_ptr, data->mlx_window, WIDTH - 20, 10, 0x00FF00,
		str);
	data->frame_count = 0;
	data->total_time = 0.0;
}

int	display_handler(t_data *data)
{
	data->start_time = clock();
	ft_new_image(data, WIDTH, HEIGHT);
	draw_background(data);
	do_rays(data, data->dir, 1);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	print_fps(data);
	return (0);
}
