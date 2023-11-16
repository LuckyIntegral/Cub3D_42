/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/16 21:13:47 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define INVALID_NUMBER "cub3d: Wrong number of arguments\n"
# define INVALID_EXTENTION "cub3d: Wrong file extention\n"
# define INVALID_FILE_CONTENT "cub3d: Wrong file content\n"

typedef enum e_error_mode
{
	DEFAULT,
	CUSTOM
}	t_error_mode;

typedef struct s_input
{
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}	t_input;

// exit utils
void	clean_input_structure(t_input *data);
void	error_handler(char *str, int mode);

// input part
void	parse_elements(t_input *data, const int fd);
void	validate_argv(const int argc, char **argv);
void	input_parser(t_input *data, char *file);

// init functions
void	init_input_structure(t_input *input);

// some utils
int		ends_with(char *str, char *format);

#endif
