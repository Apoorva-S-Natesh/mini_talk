/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:56:43 by asomanah          #+#    #+#             */
/*   Updated: 2024/05/06 10:30:28 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_ele;
	t_list	*temp;
	void	*map_cont;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	new_lst = NULL;
	while (temp)
	{
		map_cont = f(temp->content);
		new_ele = ft_lstnew(map_cont);
		if (!new_ele)
		{
			free (map_cont);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_ele);
		temp = temp->next;
	}
	return (new_lst);
}
