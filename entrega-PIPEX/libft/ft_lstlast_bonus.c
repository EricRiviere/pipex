/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:53:22 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/08 16:53:44 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>

int main(void)
{
    t_list *head = malloc(sizeof(t_list));
    t_list *second = malloc(sizeof(t_list));
    t_list *third = malloc(sizeof(t_list));

    int v1 = 1;
	int v2 = 2;
	int v3 = 3;

	head->content = &v1;
    head->next = second;

    second->content = &v2;
    second->next = third;

    third->content = &v3;
    third->next = NULL;

    t_list *result = ft_lstlast(head);
    printf("el ultimo nodo tiene %d de content.\n",*(int *)result->content);

    free(head);
    free(second);
    free(third);
    return 0;
}
*/
