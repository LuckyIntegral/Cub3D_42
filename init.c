/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:45:36 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/16 14:47:47 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_input_structure(t_input *input)
{
	input->map = NULL;
	input->north = NULL;
	input->south = NULL;
	input->west = NULL;
	input->east = NULL;
	input->floor = 0;
	input->ceiling = 0;
}
