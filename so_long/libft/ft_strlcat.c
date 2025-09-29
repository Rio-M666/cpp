/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrio <mrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:45:54 by mrio              #+#    #+#             */
/*   Updated: 2025/05/15 15:33:13 by mrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;
	unsigned int	max;

	d_len = 0;
	while (dest[d_len] != '\0')
		d_len++;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (d_len >= size)
		return (size + s_len);
	max = size - d_len - 1;
	i = 0;
	while (i < max)
	{
		if (src[i] == '\0')
			break ;
		dest[d_len + i] = src[i];
		i++;
	}
	dest[i + d_len] = '\0';
	return (s_len + d_len);
}
