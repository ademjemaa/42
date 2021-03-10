/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:04:22 by adjemaa           #+#    #+#             */
/*   Updated: 2019/11/06 20:59:14 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	elem = f(lst);
	new = elem;
	while (lst->next)
	{
		lst = lst->next;
		if (!(elem->next = f(lst)))
		{
			del(elem->content);
			free(elem);
			return (NULL);
		}
		elem = elem->next;
	}
	return (new);
}
