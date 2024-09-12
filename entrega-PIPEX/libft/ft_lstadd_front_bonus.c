/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:56:19 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/08 16:56:42 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*node1 = ft_lstnew("hola");
	t_list	*lst = node1;
	t_list	*new = ft_lstnew("nuevo hola");
	ft_lstadd_front(&lst, new);
	printf("%s \n", (char *)lst->content);
	free(new);
}
*/
