/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:20:12 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 22:25:43 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_data *data)
{
	data->player.y -= 1 * SPEED;
}

void	go_backward(t_data *data)
{
	data->player.y += 1 * SPEED;
}

// void	turn_left(t_data *data)
// {

// }

// void	turn_right(t_data *data)
// {

// }

void	go_left(t_data *data)
{
	data->player.x -= 1 * SPEED;
}

void	go_right(t_data *data)
{
	data->player.x += 1 * SPEED;
}