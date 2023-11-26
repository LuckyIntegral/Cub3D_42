/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:02:29 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/26 20:11:20 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	trim_map(t_input *data)
{
	int	last_full;
	int	row;

	last_full = 0;
	row = 0;
	while (data->map[row])
	{
		if (!ft_is_blank(data->map[row]))
			last_full = row;
		row++;
	}
	if (row == last_full)
		return ;
	while (data->map[++last_full])
	{
		free(data->map[last_full]);
		data->map[last_full] = NULL;
	}
}

int	ends_with(char *str, char *format)
{
	const int	slen = ft_strlen(str);
	const int	flen = ft_strlen(format);

	if (slen < flen)
		return (0);
	str += slen - flen;
	while (*str)
		if (*str++ != *format++)
			return (0);
	return (1);
}

void	validate_argv(const int argc, char **argv)
{
	if (argc != 2)
		error_handler(INVALID_NUMBER, CUSTOM);
	if (!ends_with(argv[1], ".cub"))
		error_handler(INVALID_EXTENTION, CUSTOM);
}
