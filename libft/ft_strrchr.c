/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:22:23 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/05 15:44:48 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (*(s + len) == (char)c)
		return ((char *)(s + len));
	while (len--)
	{
		if (*(s + len) == (char)c)
			return ((char *)(s + len));
	}
	return (NULL);
}
