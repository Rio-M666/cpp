/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:09:00 by mrio              #+#    #+#             */
/*   Updated: 2025/05/15 15:28:36 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int num)
{
	int		i;
	size_t	flag;

	i = num;
	flag = 1;
	if (i < 0)
	{
		i *= -1;
		flag++;
	}
	while (10 <= i)
	{
		i = i / 10;
		flag++;
	}
	return (flag);
}

static char	*ft_return_intmin(void)
{
	char	*res;

	res = (char *)ft_calloc(12, sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, "-2147483648", 11);
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	if (n == -2147483648)
		return (ft_return_intmin());
	size = ft_count(n) - 1;
	str = (char *)ft_calloc(size + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (10 <= n)
	{
		str[size--] = 48 + (n % 10);
		n = n / 10;
	}
	str[size] = 48 + n;
	return (str);
}
