/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:41:53 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 16:50:37 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	mlx_start_program(t_data *data)
{
	data->img = (t_image *)malloc(sizeof(t_image));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, NAME);
	if (!data->mlx_window)
		return (1);
	if (init_images(data))
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->west, 64, 0);
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
	printf("map: %s\n", data.input.map[0]);
	if (mlx_start_program(&data))
		(clean_data(&data), error_handler(MLX_CONTEXT, CUSTOM));
	// printf("data no (%s)\n", data.input.north);
	// printf("data so (%s)\n", data.input.south);
	// printf("data we (%s)\n", data.input.west);
	// printf("data ea (%s)\n", data.input.east);
	// printf("data floor (%d)\n", data.input.floor);
	// printf("data ceil (%d)\n", data.input.ceiling);

	// printf("player %c, {%d, %d}\n", data.input.player.player, data.input.player.x, data.input.player.y);

	// printf("map size: width = %d, height = %d\n", data.input.width, data.input.height);
	// for (int i = 0; i < data.input.height; i++) {
	// 	printf("%02d)%s\n", i + 1, data.input.map[i]);
	// }

	clean_data(&data);
}
