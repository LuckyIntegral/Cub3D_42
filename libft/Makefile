# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 18:41:29 by vfrants           #+#    #+#              #
#    Updated: 2023/11/16 12:23:08 by vfrants          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

SRCS	= \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_math_s.c ft_math_i.c ft_str_util.c ft_contains.c get_next_line.c \
		ft_strcat.c ft_is_blank.c ft_is_int_overflow.c ft_free_split.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

%.o		: %.c
		${CC} ${CFLAGS} -c $< -o $@ -I .

${NAME}	: ${OBJS}
		ar -rc $@ ${OBJS}

all		: ${NAME}

clean	:
		rm -f ${OBJS}

fclean	:
		rm -f ${NAME} ${OBJS}

re		: fclean all

.PHONY: all, re, clean, fclean

.SILENT:
