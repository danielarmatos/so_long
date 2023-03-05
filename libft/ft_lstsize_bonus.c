/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:32:16 by dreis-ma          #+#    #+#             */
/*   Updated: 2022/11/17 20:02:23 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	int	result;

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

	list1.content = "Hello";
	list2.content = "2";
	list3.content = "3";
	list4.content = "4";

	puts(list1.content);
	puts(begin->next->content);
	puts(begin->next->next->content);

	result = ft_lstsize(begin);

	printf("\nResult is: %i", result);
}*/
