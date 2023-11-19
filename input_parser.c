/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/19 14:59:06 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*append_offset(void *data, int size)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *) data;
	new = (char *)ft_calloc(sizeof (char), size + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	while (i < size)
		new[i++] = ' ';
	return (new);
}

int	count_max_len(t_list *list)
{
	int	mlen;

	mlen = 0;
	if (!list)
		return (0);
	while (list)
	{
		mlen = ft_max(mlen, ft_strlen((char *) list->content));
		list = list->next;
	}
	return (mlen);
}

static char	**lst_to_arr(t_list **list)
{
	const int	size = ft_lstsize(*list);
	const int	mlen = count_max_len(*list);
	static int	i = -1;
	char		**arr;
	t_list		*temp;

	if (size < 3)
		return (ft_lstclear(list, &free), NULL);
	arr = ft_calloc(sizeof (char *), size + 1);
	if (arr == NULL)
		return (ft_lstclear(list, &free), NULL);
	temp = *list;
	while (++i < size)
	{
		arr[i] = append_offset(temp->content, mlen);
		if (arr[i] == NULL)
			return (ft_free_split(arr), ft_lstclear(list, &free), NULL);
		temp = temp->next;
	}
	return (ft_lstclear(list, &free), arr);
}

static void	parse_map(t_input *data, const int fd)
{
	t_list		*node;
	t_list		*lst;
	char		*line;
	int			flag;

	flag = 1;
	lst = NULL;
	while (1)
	{
		line = get_next_line(fd, READ);
		if (flag && flag--)
			line = skip_new_lines(line, fd);
		if (line == NULL)
			break ;
		node = ft_lstnew(line);
		if (node == NULL)
			(ft_lstclear(&lst, free), free(line), exit_while_parsing(data, fd));
		ft_lstadd_back(&lst, node);
	}
	data->map = lst_to_arr(&lst);
	if (data->map == NULL)
		exit_while_parsing(data, fd);
}

void	input_parser(t_input *data, char *file)
{
	const int	fd = open(file, O_RDONLY);

	if (fd < 0)
		error_handler("open", DEFAULT);
	parse_elements(data, fd);
	parse_map(data, fd);
	get_next_line(fd, CLEAN);
	data->width = ft_strlen(data->map[0]);
	while (data->map[data->height])
		data->height++;
	if (!is_valid_map(data))
	{
		clean_input_structure(data);
		error_handler(INVALID_FILE_CONTENT, CUSTOM);
	}
	if (close(fd) == -1)
	{
		clean_input_structure(data);
		error_handler("close", DEFAULT);
	}
}
