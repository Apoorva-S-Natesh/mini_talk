/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:54 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/03 13:56:00 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del (lst->content);
		free (lst);
	}
}

/* void	del(void *content)
{
	free (content);
}

int	main(void)
{
	t_list    *node;
	int    *cont;

    node = malloc(sizeof(t_list));
    if (!node)
        return (1);
    cont = (char *)malloc(sizeof(int));
    if (!cont)
        return (1);
    *(int *)cont = 42;
    node->content = cont;
    node->next = NULL;
    ft_lstdelone(node, &del);
    return (0);
} */
