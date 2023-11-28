###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -MD -MP -Ofast -march=native -g
LINKS	= -L. -lmlx -lXext -lX11 -lm

###############################################################################
######                               LIBFT                               ######
###############################################################################

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libft.a

###############################################################################
######                             MANDATORY                             ######
###############################################################################

NAME		= cub3D
SRCSDIR		= srcs
SRCS		= \
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

OBJSDIR		= ${SRCSDIR}/objs
DEPS		= $(SRCS:${SRCSDIR}/%.c=${OBJSDIR}/%.d)
OBJS		= $(SRCS:${SRCSDIR}/%.c=${OBJSDIR}/%.o)

###############################################################################
######                               BONUS                               ######
###############################################################################

NAME_B		= cub3D_bonus
SRCSDIR_B	= srcs_bonus
SRCS_B		= \
			${SRCSDIR_B}/input_validator_bonus.c \
			${SRCSDIR_B}/exit_utils_bonus.c \
			${SRCSDIR_B}/input_parser_bonus.c \
			${SRCSDIR_B}/input_parser_2_bonus.c \
			${SRCSDIR_B}/map_validator_bonus.c \
			${SRCSDIR_B}/mlx_functions_bonus.c \
			${SRCSDIR_B}/mlx_functions_2_bonus.c \
			${SRCSDIR_B}/moves_bonus.c \
			${SRCSDIR_B}/init_bonus.c \
			${SRCSDIR_B}/rotations_bonus.c \
			${SRCSDIR_B}/do_rays_bonus.c \
			${SRCSDIR_B}/mouse_handler_bonus.c \
			${SRCSDIR_B}/click_handler_bonus.c \
			${SRCSDIR_B}/main_bonus.c \
			${SRCSDIR_B}/decide_pixel_bonus.c



OBJSDIR_B	= ${SRCSDIR_B}/objs
OBJS_B      = $(SRCS_B:${SRCSDIR_B}/%.c=${OBJSDIR_B}/%.o)
DEPS_B      = $(SRCS_B:${SRCSDIR_B}/%.c=${OBJSDIR_B}/%.d)

all		: $(NAME)

bonus	: $(NAME_B)

$(NAME)	: ${OBJS}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $@ $^ $(LINKS) -L. ${LIBFT}

${OBJSDIR}/%.o		: ${SRCSDIR}/%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes

${OBJSDIR_B}/%.o	: ${SRCSDIR_B}/%.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@ -I ./includes

clean	:
		make --no-print-directory -C ${LIBDIR} clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean	:
		make --no-print-directory -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(OBJSDIR_B) $(NAME) $(NAME_B)

$(NAME_B)	: ${OBJS_B}
		make --no-print-directory -C ${LIBDIR} all
		$(CC) $(CFLAGS) -o $(NAME_B) $^ $(LINKS) -L. ${LIBFT}

re		: fclean all

reb		: fclean bonus

test	: all
	clear; valgrind --leak-check=full --track-origins=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no --track-fds=yes -s ./$(NAME) valid_1.cub

-include $(DEPS_B) $(DEPS)

.PHONY: all clean fclean bonus re test reb
