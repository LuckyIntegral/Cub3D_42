/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:10:55 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/11 13:24:59 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	len;

	len = ft_nbrlen(n);
	new = (char *)malloc(sizeof (char) * (++len));
	if (!new)
		return (NULL);
	new[--len] = '\0';
	if (!n)
		new[--len] = '0';
	while (n)
	{
		new[--len] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	if (len)
		new[--len] = '-';
	return (new);
}
