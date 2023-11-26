/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:19:58 by dgutak            #+#    #+#             */
/*   Updated: 2023/11/26 20:08:18 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_data *data, t_point p, int x, double y)
{
	double	tx;
	double	ty;
	int		i;

	tx = (int)(p.x) % IMAGE_SIZE;
	ty = (int)(p.y) % IMAGE_SIZE;
	i = HEIGHT / 2 - x - 1;
	while (++i < HEIGHT / 2 + x)
	{
		if ((int)tx == 0)
			data->img->pixels[WIDTH * i + data->ray_num]
				= data->east_img->pixels[(int)y * IMAGE_SIZE + (int)ty];
		else if ((int)ty == 0)
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->south_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)tx];
		else if ((int)tx == IMAGE_SIZE - 1)
			data->img->pixels[WIDTH * i
				+ data->ray_num] = data->west_img->pixels[(int)y * IMAGE_SIZE
				+ IMAGE_SIZE - 1 - (int)ty];
		else if ((int)ty == IMAGE_SIZE - 1)
			data->img->pixels[WIDTH * i + data->ray_num]
				= data->north_img->pixels[(int)y * IMAGE_SIZE + (int)tx];
		y += data->ty_step;
	}
}

void	draw_view(t_data *data, double dist, t_point p)
{
	int		x;
	double	ty_off;
	double	y;

	x = (int)(IMAGE_SIZE * HEIGHT / 2 / dist);
	ty_off = 0;
	data->ty_step = 1024.0 / (double)(2 * x);
	if (x > HEIGHT / 2)
	{
		ty_off = (x - HEIGHT / 2);
		x = HEIGHT / 2;
	}
	y = ty_off * data->ty_step;
	put_pixel(data, p, x, y);
}

void	try_draw(t_data *data, t_point p1, double ex)
{
	if (data->input.map[(int)p1.y / IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] == ' ')
		p1.x -= ex;
	draw_view(data, sqrt(pow(data->player.y - p1.y, 2) + pow(data->player.x
				- p1.x, 2)) * cos(fabs(data->ray_angle)), p1);
}

void	bresenham(t_data *data, t_point p1, t_point p2, double length)
{
	double	ex;
	double	ey;
	double	max;

	ex = p2.x - p1.x;
	ey = p2.y - p1.y;
	max = fmax(fabs(ex), fabs(ey));
	ey /= max;
	ex /= max;
	p2.x += ex * length;
	p2.y += ey * length;
	while (1)
	{
		if (IMAGE_SIZE * data->input.width > p1.x && IMAGE_SIZE
			* data->input.height > p1.y && data->input.map[(int)p1.y
				/ IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] != '0')
		{
			try_draw(data, p1, ex);
			break ;
		}
		p1.x += ex;
		p1.y += ey;
	}
}

void	do_rays(t_data *data, t_point dir, double length)
{
	t_point	p;
	double	del_x;
	double	del_y;

	data->ray_num = -1;
	p.x = data->player.x;
	p.y = data->player.y;
	p.color = 0x5500FF00;
	del_x = (dir.x - data->player.x);
	del_y = (dir.y - data->player.y);
	dir.x = (del_x * cos(-FOV / 2) - del_y * sin(-FOV / 2)) + data->player.x;
	dir.y = (del_x * sin(-FOV / 2) + del_y * cos(-FOV / 2)) + data->player.y;
	data->ray_angle = -FOV / 2;
	while (++data->ray_num < WIDTH)
	{
		bresenham(data, p, dir, length);
		del_x = (dir.x - data->player.x);
		del_y = (dir.y - data->player.y);
		dir.x = (del_x * cos(FOV / WIDTH) - del_y * sin(FOV / WIDTH))
			+ data->player.x;
		dir.y = (del_x * sin(FOV / WIDTH) + del_y * cos(FOV / WIDTH))
			+ data->player.y;
		data->ray_angle += FOV / WIDTH;
	}
}
