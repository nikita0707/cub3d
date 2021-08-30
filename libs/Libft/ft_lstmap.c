/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:48:03 by rmass             #+#    #+#             */
/*   Updated: 2020/11/03 19:03:49 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;
	t_list	*newc;

	temp = lst;
	res = 0;
	while (temp)
	{
		if (!f)
			return (0);
		if (!(newc = ft_lstnew(f(lst->content))))
			return (0);
		ft_lstadd_back(&res, newc);
		temp = temp->next;
	}
	if (del)
		del(temp);
	return (res);
}
