/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/20 14:03:02 by dgutak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <X11/keysym.h>

# define NAME "Cub 3D"

# define MLX_CONTEXT "mlx: Cannot establish connection\n"
# define INVALID_NUMBER "cub3d: Wrong number of arguments\n"
# define INVALID_EXTENTION "cub3d: Wrong file extention\n"
# define INVALID_FILE_CONTENT "cub3d: Wrong file content\n"

// screen size
# define WIDTH 1536
# define HEIGHT 767

// keys
# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define A 97
# define S 115
# define D 100

// random
# define CROSS 17
# define SPEED 10

typedef enum e_error_mode
{
	DEFAULT,
	CUSTOM
}	t_error_mode;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_player
{
	char	player;
	int		x;
	int		y;
	int		dx;
	int		dy;
}	t_player;

typedef struct s_input
{
	char	**map;
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
}	t_input;
typedef struct s_image
{
	void	*reference;
	int		*pixels;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;

}			t_image;
// Maybe later i will rewrite everything into one struct, but i dont think so:)
// Feel free rewrite it:)
typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_input		input;
	t_player	player;
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	t_image		*img;
}	t_data;

// mlx utils
int		key_handler(int key, t_data *data);

// rotation v1
void	go_right(t_data *data);
void	go_left(t_data *data);
void	go_backward(t_data *data);
void	go_forward(t_data *data);

// exit utils
void	clean_input_structure(t_input *data);
void	error_handler(char *str, int mode);
void	clean_data(t_data *data);
int		close_game(t_data *data);

// map validation
int		is_valid_map(t_data *data);
void	trim_map(t_input *data);

// input part
void	parse_elements(t_input *data, const int fd);
void	validate_argv(const int argc, char **argv);
void	exit_while_parsing(t_input *data, int fd);
char	*skip_new_lines(char *str, const int fd);
void	input_parser(t_input *data, char *file);

// init functions
void	init_structure(t_data *input);
int		display_handler(t_data *data);
int		init_images(t_data *data);

// some utils
int		ends_with(char *str, char *format);

#endif
