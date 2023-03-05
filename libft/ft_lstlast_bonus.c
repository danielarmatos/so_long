/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:32:46 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/18 19:44:01 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*result;

	t_list list1;
	t_list list2;
	t_list list3;
	t_list list4;
	t_list *begin;

	begin = &list1;
	list1.next = &list2;
	list2.next = &list3;
	list3.next = &list4;
	list4.next = 0;

	list4.content = "Content of last element list4";

	result = ft_lstlast(begin);
	puts(result->content);
}*/	
