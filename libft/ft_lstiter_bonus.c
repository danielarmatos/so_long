/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:35:00 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/17 19:57:06 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
void	ft_test(void *x)
{
	(void)x;
}

int	main(void)
{
	t_list list1;
	t_list list2;
	t_list list3;
	t_list *begin;

	begin = &list1;
	list1.next = &list2;
	list2.next = &list3;
	list3.next = 0;

	list1.content = "1";
	list2.content = "lala 2";
	list3.content = "Content of last element list3";
	puts(list1.content);
	puts(list2.content);
	puts(list3.content);
	
	ft_lstiter(begin, ft_test);
	puts(list1.content);
	puts(list2.content);
	puts(list3.content);	
}*/
