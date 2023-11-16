/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:59 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/12 13:56:26 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_tr_nul(const char *condition, const char *t, const char *f)
{
	if (!condition)
		return (t);
	return (f);
}

void	*ft_tr_str(int condition, void *t, void *f)
{
	if (condition)
		return (t);
	return (f);
}
