/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:39:04 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/05 15:43:13 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*csrc;
	char		*cdst;

	cdst = dst;
	csrc = src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		while (len--)
			cdst[len] = csrc[len];
	return (dst);
}
