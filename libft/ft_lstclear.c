/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:33:40 by vfrants           #+#    #+#             */
/*   Updated: 2023/11/28 17:25:49 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*this;

	if (!lst || !del)
		return ;
	this = *lst;
	while (this)
	{
		next = this->next;
		ft_lstdelone(this, del);
		this = next;
	}
	*lst = NULL;
}
