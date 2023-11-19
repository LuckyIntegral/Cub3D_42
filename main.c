/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:41:53 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 18:29:16 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_input	input;

	validate_argv(argc, argv);
	init_input_structure(&input);
	input_parser(&input, argv[1]);

	printf("data no (%s)\n", input.north);
	printf("data so (%s)\n", input.south);
	printf("data we (%s)\n", input.west);
	printf("data ea (%s)\n", input.east);
	printf("data floor (%d)\n", input.floor);
	printf("data ceil (%d)\n", input.ceiling);

	printf("player %c, {%d, %d}\n", input.player.player, input.player.x, input.player.y);

	printf("map size: width = %d, height = %d\n", input.width, input.height);
	for (int i = 0; i < input.height; i++) {
		printf("%02d)%s\n", i + 1, input.map[i]);
	}

	clean_input_structure(&input);
}
