/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:53:48 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/05 15:46:12 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strstr(const char *a, const char *b, size_t len)
{
	while (*a && *a == *b && len--)
	{
		a++;
		b++;
	}
	return (!*b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle)
			if (ft_strstr(haystack + i, needle, len - i))
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
