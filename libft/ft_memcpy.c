/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:38:20 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/05 15:43:03 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdst;

	if (dst == src || !n)
		return (dst);
	cdst = dst;
	csrc = src;
	while (n--)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
	}
	return (dst);
}
