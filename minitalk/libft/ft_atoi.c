/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:31 by mrio              #+#    #+#             */
/*   Updated: 2025/05/16 16:23:44 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_check(const char *nptr, int *flag)
{
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	*flag = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*flag = -1;
		i++;
	}
	return (i);
}

static int	ft_check_over(int flag, long word, int digit)
{
	if (flag == 1)
	{
		if (word > (LONG_MAX - digit) / 10)
			return (-1);
	}
	else
	{
		if (word < (LONG_MIN + digit) / 10)
			return (0);
	}
	return (2);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	long	word;
	int		digit;
	int		chk_o;

	i = ft_check(nptr, &flag);
	word = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i++] - '0';
		chk_o = ft_check_over(flag, word, digit);
		if (chk_o != 2)
			return (chk_o);
		word = (word * 10) + digit;
	}
	return ((int)(word * flag));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", atoi("-109"));
// 	printf("%d\n", ft_atoi("-109"));
// 	return (0);
// }