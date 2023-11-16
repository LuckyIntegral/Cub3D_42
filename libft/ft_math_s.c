/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:16:46 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/11 15:12:49 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_min_s(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_max_s(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_abs(int a)
{
	if (a > 0)
		return ((size_t) a);
	if (a == -2147483648)
		return ((size_t) 2147483648);
	return ((size_t) a * -1);
}
