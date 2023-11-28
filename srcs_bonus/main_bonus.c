/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:41:53 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/28 15:31:29 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	alloc_textures(t_data *data)
{
	data->img = (t_image *)malloc(sizeof(t_image));
	data->east_img = (t_image *)malloc(sizeof(t_image));
	data->north_img = (t_image *)malloc(sizeof(t_image));
	data->south_img = (t_image *)malloc(sizeof(t_image));
	data->west_img = (t_image *)malloc(sizeof(t_image));
	data->door_img = (t_image *)malloc(sizeof(t_image));
	data->gun_img = (t_image *)malloc(sizeof(t_image));
	if (!data->east_img || !data->img || !data->north_img || !data->south_img
		|| !data->west_img || !data->door_img || !data->gun_img)
		return (1);
	data->west_img->reference = NULL;
	data->north_img->reference = NULL;
	data->south_img->reference = NULL;
	data->door_img->reference = NULL;
	data->east_img->reference = NULL;
	data->gun_img->reference = NULL;
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
