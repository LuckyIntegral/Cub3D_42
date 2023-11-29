/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:08:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/29 13:06:12 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_data *data)
{
	clean_data(data);
	exit(0);
	return (0);
}

void	error_handler(char *str, int mode)
{
	write(2, "Error\n", 6);
	if (mode == DEFAULT)
		perror(str);
	else
		write(2, str, ft_strlen(str));
	exit(1);
}

void	clean_data(t_data *data)
{
	if (data->east_img && data->east_img->reference)
		mlx_destroy_image(data->mlx_ptr, data->east_img->reference);
	if (data->west_img && data->west_img->reference)
		mlx_destroy_image(data->mlx_ptr, data->west_img->reference);
	if (data->south_img && data->south_img->reference)
		mlx_destroy_image(data->mlx_ptr, data->south_img->reference);
	if (data->north_img && data->north_img->reference)
		mlx_destroy_image(data->mlx_ptr, data->north_img->reference);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	if (data->mlx_ptr)
		(mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr));
	if (data->img)
		free(data->img);
	if (data->east_img)
		free(data->east_img);
	if (data->north_img)
		free(data->north_img);
	if (data->south_img)
		free(data->south_img);
	if (data->west_img)
		free(data->west_img);
	clean_input_structure(&data->input);
}

void	clean_input_structure(t_input *data)
{
	if (data->north)
	{
		free(data->north);
		data->north = NULL;
	}
	if (data->south)
	{
		free(data->south);
		data->north = NULL;
	}
	if (data->west)
	{
		free(data->west);
		data->north = NULL;
	}
	if (data->east)
	{
		free(data->east);
		data->north = NULL;
	}
	if (data->map)
	{
		ft_free_split(data->map);
		data->map = NULL;
	}
}
