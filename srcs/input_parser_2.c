/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:10:14 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/27 22:20:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_new_lines(char *str, const int fd)
{
	while (str && ft_is_blank(str))
	{
		free(str);
		str = get_next_line(fd, READ);
	}
	return (str);
}

void	exit_while_parsing(t_input *data, int fd)
{
	close(fd);
	get_next_line(fd, CLEAN);
	clean_input_structure(data);
	error_handler(INVALID_FILE_CONTENT, CUSTOM);
}

static int	is_valid_rgb(char *str)
{
	const int	len = ft_strlen(str);
	int			i;
	int			j;

	if (len < 8 || !ft_contains("CF", *str++) || *str++ != ' ')
		return (0);
	while (*str == ' ')
		str++;
	if (*str == '\0' || *str == '\n')
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
		while (*str == ' ' || *str == '\t')
			str++;
	}
	return (1);
}

static int	take_val(char *str, t_input *data)
{
	char	*res;

	if (!str)
		return (1);
	if (ft_strlen(str) < 8 || !ends_with(str, ".xpm\n")
		|| !(!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "WE ", 3)))
		return (1);
	res = ft_strtrim(str + 3, " \n");
	if (!res)
		return (1);
	if (*str == 'N')
		data->north = res;
	else if (*str == 'S')
		data->south = res;
	else if (*str == 'E')
		data->east = res;
	else
		data->west = res;
	return (0);
}

void	parse_elements(t_input *data, const int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (i++ < 6)
	{
		temp = skip_new_lines(get_next_line(fd, READ), fd);
		if (temp == NULL)
			exit_while_parsing(data, fd);
		if (is_valid_rgb(temp) && *temp == 'C')
			data->ceiling = (ft_atoi(temp + 2) << 16)
				+ (ft_atoi(ft_strchr(temp + 2, ',') + 1) << 8)
				+ (ft_atoi(ft_strrchr(temp + 2, ',') + 1));
		else if (is_valid_rgb(temp))
			data->floor = (ft_atoi(temp + 2) << 16)
				+ (ft_atoi(ft_strchr(temp + 2, ',') + 1) << 8)
				+ (ft_atoi(ft_strrchr(temp + 2, ',') + 1));
		else if (take_val(temp, data))
		{
			free(temp);
			exit_while_parsing(data, fd);
		}
		free(temp);
	}
}
