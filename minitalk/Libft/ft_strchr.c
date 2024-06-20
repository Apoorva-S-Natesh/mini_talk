/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:06:46 by asomanah          #+#    #+#             */
/*   Updated: 2024/04/29 13:18:54 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == find)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == find)
		return ((char *) &s[i]);
	return (NULL);
}
