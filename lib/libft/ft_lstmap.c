/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:41:09 by agouby            #+#    #+#             */
/*   Updated: 2016/11/14 13:32:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}
