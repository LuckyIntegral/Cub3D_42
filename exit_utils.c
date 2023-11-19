/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:08:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 20:59:51 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	close_game(t_data *data)
{
	clean_data(data);
	exit(0);
	return (0);
}

void	error_handler(char *str, int mode)
{
	write(2, "Error,\n", 7);
	if (mode == DEFAULT)
		perror(str);
	else
		write(2, str, ft_strlen(str));
	exit(1);
}

// for everything
void	clean_data(t_data *data)
{
	if (data->east)
		mlx_destroy_image(data->mlx_ptr, data->east);
	if (data->west)
		mlx_destroy_image(data->mlx_ptr, data->west);
	if (data->south)
		mlx_destroy_image(data->mlx_ptr, data->south);
	if (data->north)
		mlx_destroy_image(data->mlx_ptr, data->north);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	if (data->mlx_ptr)
		(mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr));
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
