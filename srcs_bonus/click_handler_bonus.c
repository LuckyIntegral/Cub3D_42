/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:22:38 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/28 14:54:54 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	on_click(int code, t_data *data)
{
	data->frame_count = 1;
	(void)code;
	return (0);
}
