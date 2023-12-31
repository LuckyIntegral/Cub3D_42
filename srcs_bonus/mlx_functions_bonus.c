/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:08:10 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/28 16:10:32 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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
	char	str[20];
	int		i;

	data->end_time = clock();
	ft_bzero(str, 20 * sizeof(char));
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

void	put_gun(t_data *data)
{
	int			i;
	int			j;
	int			pix;
	static int	frame;

	i = -1;
	while (++i < 828)
	{
		j = 2388 / 4 * (data->gun_frame - 1) - 1;
		while (++j < 2388 / 4 * data->gun_frame)
		{
			pix = data->gun_img->pixels[2388 * i + j];
			if (pix != 0xFFFFFF && i > 30)
				data->img->pixels[WIDTH * (i + 75) + (j - 2388 / 4
						* (data->gun_frame - 1)) + 570] = pix;
		}
	}
	frame++;
	if (!(data->shoot == 1 && frame % 2 == 0))
		return ;
	if (++data->gun_frame == 5 && data->shoot--)
	{
		data->gun_frame = 1;
		frame = 0;
	}
}

int	display_handler(t_data *data)
{
	data->start_time = clock();
	bound_mouse(data);
	ft_new_image(data, WIDTH, HEIGHT);
	draw_background(data);
	do_rays(data, data->dir, 1);
	draw_minimap(data);
	put_gun(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->img->reference, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img->reference);
	print_fps(data);
	return (0);
}
