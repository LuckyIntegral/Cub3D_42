/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:44 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/28 13:34:19 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# define NAME "Cub 3D"

# define MLX_CONTEXT "mlx: Cannot establish connection\n"
# define INVALID_NUMBER "cub3d: Wrong number of arguments\n"
# define INVALID_EXTENTION "cub3d: Wrong file extention\n"
# define INVALID_FILE_CONTENT "cub3d: Wrong file content\n"

// screen size
# define WIDTH 1600
# define HEIGHT 900

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
# define IMAGE_SIZE 1024
# define SPEED 200
# define ROTATE_SPEED 0.174533
# define MOUSE_ROTATE_SPEED 0.0523599
# define DIR_L 100
# define FOV 1.0472

// minimap utils
# define MMAP_RADIUS 10
# define MMAP_SIZE 8
# define MMAP_BORDER 0x0000FF // Blue
# define MMAP_PLAYER 0xFF0000 // Red
# define MMAP_EMPTY 0x00FF00 // Green
# define MMAP_WALL 0x808080 // Gray
# define MMAP_CLOSED_DOOR 0x800000 // Dark Orange
# define MMAP_DOOR 0x000000  // Orange

// map macroses
# define EMPTY '0'
# define WALL '1'
# define DOOR_OPEN 'D'
# define DOOR_CLOSED 'C'

typedef enum e_error_mode
{
	DEFAULT,
	CUSTOM
}				t_error_mode;

typedef struct s_player
{
	char		player;
	double		x;
	double		y;
}				t_player;

typedef struct s_point
{
	double		x;
	double		y;
	int			color;
}				t_point;

typedef struct s_input
{
	char		**map;
	int			width;
	int			height;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceiling;
}				t_input;

typedef struct s_image
{
	void		*reference;
	int			*pixels;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_input		input;
	t_player	player;
	t_image		*img;
	t_image		*east_img;
	t_image		*west_img;
	t_image		*north_img;
	t_image		*south_img;
	t_image		*door_img;
	t_point		dir;
	t_point		plane;
	t_point		plane2;
	double		total_time;
	int			frame_count;
	int			fps;
	int			ray_num;
	double		ray_angle;
	double		ty_step;
	clock_t		start_time;
	clock_t		end_time;
}				t_data;

// mlx utils
void			bresenham(t_data *data, t_point p1, t_point p2, double length);
void			ft_new_image(t_data *data, int width, int height);
void			draw_cell(t_data *data, int x, int y, int color);
void			draw_minimap(t_data *data);
int				key_handler(int key, t_data *data);
void			do_rays(t_data *data, t_point dir, double length);

// rotation v1
void			go_right(t_data *data);
void			go_left(t_data *data);
void			go_backward(t_data *data);
void			go_forward(t_data *data);
void			turn_left(t_data *data);
void			turn_right(t_data *data);
void			rotate_vec(double *beg_x, double *beg_y, double *end_x,
					double *end_y);
void			rotate_vec_back(double *beg_x, double *beg_y, double *end_x,
					double *end_y);
int				key_handler(int key, t_data *data);
void			bound_mouse(t_data *data);
void			open_doors(t_data *data);
int				on_click(int code, t_data *data);

// exit utils
void			clean_input_structure(t_input *data);
void			error_handler(char *str, int mode);
void			clean_data(t_data *data);
int				close_game(t_data *data);

// map validation
int				is_valid_map(t_data *data);
void			trim_map(t_input *data);
void			set_camera(t_data *data, int x, int y);

// input part
void			parse_elements(t_input *data, const int fd);
void			validate_argv(const int argc, char **argv);
void			exit_while_parsing(t_input *data, int fd);
char			*skip_new_lines(char *str, const int fd);
void			input_parser(t_input *data, char *file);

// init functions
void			init_structure(t_data *input);
int				display_handler(t_data *data);
int				init_images(t_data *data);

// some utils
int				ends_with(char *str, char *format);

#endif
