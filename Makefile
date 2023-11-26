NAME	= cub3D
NAME_B	= cub3D_bonus
CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -MD -MP -Ofast -march=native
LINKS	= -L. -lmlx -lXext -lX11 -lm

SRCSDIR		= srcs
SRCSDIR_B	= srcs_bonus
LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libft.a

SRCS	= \
		${SRCSDIR}/exit_utils.c \
		${SRCSDIR}/input_validator.c \
		${SRCSDIR}/input_parser.c \
		${SRCSDIR}/input_parser_2.c \
		${SRCSDIR}/map_validator.c \
		${SRCSDIR}/mlx_functions.c \
		${SRCSDIR}/mlx_functions_2.c \
		${SRCSDIR}/moves.c \
		${SRCSDIR}/init.c \
		${SRCSDIR}/rotations.c \
		${SRCSDIR}/do_rays.c \
		${SRCSDIR}/main.c

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

SRCS_B	= \
		${SRCSDIR_B}/exit_utils_bonus.c \
		${SRCSDIR_B}/input_validator_bonus.c \
		${SRCSDIR_B}/input_parser_bonus.c \
		${SRCSDIR_B}/input_parser_2_bonus.c \
		${SRCSDIR_B}/map_validator_bonus.c \
		${SRCSDIR_B}/mlx_functions_bonus.c \
		${SRCSDIR_B}/mlx_functions_2_bonus.c \
		${SRCSDIR_B}/moves_bonus.c \
		${SRCSDIR_B}/init_bonus.c \
		${SRCSDIR_B}/rotations_bonus.c \
		${SRCSDIR_B}/do_rays_bonus.c \
		${SRCSDIR_B}/main_bonus.c

OBJS_B      = $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.o))
DEPS_B      = $(addprefix $(OBJS_DIR)/, $(SRCS_B:.c=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $@ $^ $(LINKS) -L. ${LIBFT}

objs/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes

clean	:
		make --no-print-directory -C ${LIBDIR} clean
		$(RM) $(OBJS_DIR)

fclean	:
		make --no-print-directory -C ${LIBDIR} fclean
		$(RM) $(OBJS_DIR) $(NAME) $(NAME_B)

bonus	: ${OBJS_B}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $(NAME_B) $^ $(LINKS) -L. ${LIBFT}

re		: fclean all

reb		: fclean bonus

test	: all
	clear; valgrind --leak-check=full --track-origins=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no -s ./$(NAME) maps/valid_1.cub

-include $(DEPS_B) $(DEPS)

.PHONY: all clean fclean bonus re test reb
