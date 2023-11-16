/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:09:02 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/09 17:08:34 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int_overflow(char *str)
{
	long int	res;
	int			flag;

	res = 0;
	flag = 0;
	if (*str == '-')
	{
		flag = 1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		res = (res * 10) + (*str - '0');
		str++;
		if ((res * ft_tr(flag, -1l, 1l)) > 2147483647
			|| (res * ft_tr(flag, -1l, 1l)) < -2147483648)
			return (1);
	}
	return (0);
}
