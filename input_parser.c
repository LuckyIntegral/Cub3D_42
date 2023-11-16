/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/16 21:14:45 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_parser(t_input *data, char *file)
{
	const int	fd = open(file, O_RDONLY);

	if (fd < 0)
		error_handler("open", DEFAULT);
	parse_elements(data, fd);
	get_next_line(fd, CLEAN);
	close(fd);
}
