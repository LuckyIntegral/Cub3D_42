/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:35:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/05 16:13:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	void	*temp_content;

	if (!lst)
		return (NULL);
	new_list = 0;
	while (lst)
	{
		temp_content = f(lst->content);
		if (temp_content)
			temp = ft_lstnew(temp_content);
		if (!temp || !temp_content)
		{
			ft_lstclear(&new_list, del);
			del(temp_content);
			if (!temp)
				free(temp);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
