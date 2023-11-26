NAME	= cub3D
CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -MD -MP -Ofast -march=native
LINKS	= -L. -lmlx -lXext -lX11 -lm

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libft.a

SRCS	= exit_utils.c input_validator.c input_parser.c input_parser_2.c \
		map_validator.c mlx_functions.c mlx_functions_2.c moves.c init.c main.c do_rays.c rotations.c

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

all		: $(NAME)

$(NAME)	: ${OBJS}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $@ $^ $(LINKS) -L. ${LIBFT}

objs/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I .

clean	:
		make --no-print-directory -C ${LIBDIR} clean
		$(RM) $(OBJS_DIR)

fclean	:
		make --no-print-directory -C ${LIBDIR} fclean
		$(RM) $(OBJS_DIR) $(NAME)

re		: fclean all

test	: all
	clear; valgrind --leak-check=full --track-origins=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no -s ./$(NAME) maps/valid_1.cub

-include $(DEPS)

.PHONY: all clean fclean re test
