/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyachirio <miyachirio@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:49:38 by mrio              #+#    #+#             */
/*   Updated: 2025/05/04 01:53:23 by miyachirio       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*s;
	size_t		i;
	char		ch;

	s = NULL;
	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			s = &str[i];
		i++;
	}
	if (ch == '\0')
		return ((char *)&str[i]);
	return ((char *)s);
}
