/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:05:09 by asomanah          #+#    #+#             */
/*   Updated: 2024/04/30 12:14:22 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*temp;

	total = nmemb * size;
	i = 0;
	if (nmemb && size && nmemb > ((size_t) - 1 / size))
		return (NULL);
	temp = malloc(total);
	if (!temp)
		return (NULL);
	while (i < total)
		temp[i++] = 0;
	return (temp);
}
