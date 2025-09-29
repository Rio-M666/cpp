/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:13 by mrio              #+#    #+#             */
/*   Updated: 2025/04/30 15:07:28 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*copy;
	char		*dest;
	int			len;
	int			i;

	copy = s;
	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = copy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
