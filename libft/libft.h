/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:33:31 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/18 16:53:42 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef GNL_BUFFER
#  define GNL_BUFFER 10
# endif

# define READ 0
# define CLEAN 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Part 1

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

// Part 2

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);

// Part 3 (bonus)

t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_front(t_list **lst, t_list *_new);
void		ft_lstadd_back(t_list **lst, t_list *_new);
int			ft_lstsize(t_list *lst);

// Custom functions
char		*get_next_line(int fd, int mode);

// Ternarnary functions
int			ft_tr(int condition, int t, int f);
int			ft_max(int a, int b);
int			ft_min(int a, int b);

size_t		ft_min_s(size_t a, size_t b);
size_t		ft_max_s(size_t a, size_t b);
size_t		ft_abs(int a);

const char	*ft_tr_nul(const char *condition, const char *t, const char *f);
void		*ft_tr_str(int condition, void *t, void *f);

// String utils
char		*ft_strcat(const char *s1, const char *s2);
int			ft_contains(const char *set, char c);
int			ft_is_blank(const char *str);

// Should be helpful
void		ft_free_split(char **strs);
int			ft_is_int_overflow(char *str);

#endif
