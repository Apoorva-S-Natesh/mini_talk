/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:06 by asomanah          #+#    #+#             */
/*   Updated: 2024/04/29 13:10:08 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		i;

	i = ft_strlen(s);
	find = (char)c;
	while (i >= 0)
	{
		if (s[i] == find)
		{
			return ((char *) &s[i]);
		}
		i--;
	}
	return (NULL);
}
