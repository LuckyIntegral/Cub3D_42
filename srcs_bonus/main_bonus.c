/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:41:53 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/29 13:02:08 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	clean_child(t_data *data)
{
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
	if (data->door_img)
		free(data->door_img);
	if (data->gun_img)
		free(data->gun_img);
	clean_input_structure(&data->input);
	exit(1);
}

int	alloc_texture_2(t_data *data)
{
	data->door_img = (t_image *)malloc(sizeof(t_image));
	if (!data->door_img)
		return (1);
	ft_bzero(data->door_img, sizeof(t_image));
	data->gun_img = (t_image *)malloc(sizeof(t_image));
	if (!data->gun_img)
		return (1);
	ft_bzero(data->gun_img, sizeof(t_image));
	return (0);
}

int	alloc_textures(t_data *data)
{
	data->img = (t_image *)malloc(sizeof(t_image));
	if (!data->img)
		return (1);
	ft_bzero(data->img, sizeof(t_image));
	data->east_img = (t_image *)malloc(sizeof(t_image));
	if (!data->east_img)
		return (1);
	ft_bzero(data->east_img, sizeof(t_image));
	data->north_img = (t_image *)malloc(sizeof(t_image));
	if (!data->north_img)
		return (1);
	ft_bzero(data->north_img, sizeof(t_image));
	data->south_img = (t_image *)malloc(sizeof(t_image));
	if (!data->south_img)
		return (1);
	ft_bzero(data->south_img, sizeof(t_image));
	data->west_img = (t_image *)malloc(sizeof(t_image));
	if (!data->west_img)
		return (1);
	ft_bzero(data->west_img, sizeof(t_image));
	if (alloc_texture_2(data))
		return (1);
	return (0);
}

int	mlx_start_program(t_data *data)
{
	if (alloc_textures(data))
		return (1);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, NAME);
	if (!data->mlx_window)
		return (1);
	if (init_images(data))
		return (1);
	mlx_hook(data->mlx_window, 2, 1L, &key_handler, data);
	mlx_hook(data->mlx_window, CROSS, 0L, &close_game, data);
	mlx_loop_hook(data->mlx_ptr, &display_handler, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_argv(argc, argv);
	init_structure(&data);
	input_parser(&data.input, argv[1]);
	if (!is_valid_map(&data))
		(clean_data(&data), error_handler(INVALID_FILE_CONTENT, CUSTOM));
	if (mlx_start_program(&data))
		(clean_data(&data), error_handler(MLX_CONTEXT, CUSTOM));
	clean_data(&data);
}
