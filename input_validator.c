/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:02:29 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/16 21:13:31 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
