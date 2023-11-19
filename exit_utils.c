/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:08:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 15:00:02 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(char *str, int mode)
{
	write(2, "Error,\n", 7);
	if (mode == DEFAULT)
		perror(str);
	else
		write(2, str, ft_strlen(str));
	exit(1);
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
