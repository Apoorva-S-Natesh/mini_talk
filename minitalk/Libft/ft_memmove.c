/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 00:42:34 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/02 15:30:08 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && s == NULL)
		return (NULL);
	if (dst < s)
	{
		while (i < n)
		{
			dst[i] = s[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			dst[n] = s[n];
	}
	return (dst);
}
