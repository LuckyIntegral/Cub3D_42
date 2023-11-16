/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:24:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/11 15:09:56 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		size;
	char		*new;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	size = ft_min(ft_strlen(s + start), len);
	new = (char *)ft_calloc(sizeof (char), size + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, size + 1);
	return (new);
}
