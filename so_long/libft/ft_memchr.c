/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:24:48 by mrio              #+#    #+#             */
/*   Updated: 2025/04/29 17:31:36 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	j;

	i = (unsigned char *)s;
	j = (unsigned char)c;
	while (n--)
	{
		if (*i == j)
			return ((void *)i);
		i++;
	}
	return (0);
}
