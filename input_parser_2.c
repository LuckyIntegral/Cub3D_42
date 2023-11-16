/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:10:14 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/16 21:10:53 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_new_lines(char *str, const int fd)
{
	while (str && ft_is_blank(str))
	{
		free(str);
		str = get_next_line(fd, READ);
	}
	return (str);
}

static void	exit_while_parsing(t_input *data, int fd)
{
	close(fd);
	get_next_line(fd, CLEAN);
	clean_input_structure(data);
	error_handler(INVALID_FILE_CONTENT, CUSTOM);
}

static int	is_valid_rgb(char *str, char item)
{
	const int	len = ft_strlen(str);
	int			i;
	int			j;

	if (len < 8 || len > 14)
		return (0);
	if (item == 'F' && *str++ != 'F')
		return (0);
	else if (item == 'C' && *str++ != 'C')
		return (0);
	if (*str++ != ' ')
		return (0);
	j = 0;
	while (j++ < 3)
	{
		i = 0;
		while (ft_isdigit(str[i]) && i < 3)
			i++;
		if ((j != 3 && str[i] != ',') || (j == 3 && str[i] != '\n'))
			return (0);
		str += i + 1;
	}
	return (1);
}

static char	*take_val(char *str, char *direction)
{
	char	*res;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < 4 || ft_strncmp(str, direction, 3))
		return (free(str), NULL);
	res = ft_strdup(str + 3);
	return (free(str), res);
}

void	parse_elements(t_input *data, const int fd)
{
	char	*temp;

	data->north = take_val(skip_new_lines(get_next_line(fd, READ), fd), "NO ");
	if (!data->north)
		exit_while_parsing(data, fd);
	data->south = take_val(skip_new_lines(get_next_line(fd, READ), fd), "SO ");
	if (!data->south)
		exit_while_parsing(data, fd);
	data->west = take_val(skip_new_lines(get_next_line(fd, READ), fd), "WE ");
	if (!data->west)
		exit_while_parsing(data, fd);
	data->east = take_val(skip_new_lines(get_next_line(fd, READ), fd), "EA ");
	if (!data->east)
		exit_while_parsing(data, fd);
	temp = skip_new_lines(get_next_line(fd, READ), fd);
	if (!temp || !is_valid_rgb(temp, 'F'))
		(free(temp), exit_while_parsing(data, fd));
	data->floor = (ft_atoi(temp + 2) << 16) + (ft_atoi(ft_strchr(temp, ','))
			<< 8) + (ft_atoi(ft_strrchr(temp, ',')));
	(free(temp), temp = skip_new_lines(get_next_line(fd, READ), fd));
	if (!temp || !is_valid_rgb(temp, 'C'))
		(free(temp), exit_while_parsing(data, fd));
	data->ceiling = (ft_atoi(temp + 2) << 16) + (ft_atoi(ft_strchr(temp, ','))
			<< 8) + (ft_atoi(ft_strrchr(temp, ',')));
	free(temp);
}
