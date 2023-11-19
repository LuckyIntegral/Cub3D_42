/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 18:09:14 by vfrants          ###   ########.fr       */
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

typedef struct s_player
{
	char	player;
	int		x;
	int		y;
}	t_player;

typedef struct s_input
{
	char		**map;
	t_player	player;
	int			width;
	int			height;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceiling;
}	t_input;

// exit utils
void	clean_input_structure(t_input *data);
void	error_handler(char *str, int mode);

// map validation
int		is_valid_map(t_input *data);

// input part
void	parse_elements(t_input *data, const int fd);
void	validate_argv(const int argc, char **argv);
void	exit_while_parsing(t_input *data, int fd);
char	*skip_new_lines(char *str, const int fd);
void	input_parser(t_input *data, char *file);
void	trim_map(t_input *data);

// init functions
void	init_input_structure(t_input *input);

// some utils
int		ends_with(char *str, char *format);

#endif
