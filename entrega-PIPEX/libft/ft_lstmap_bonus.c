/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:59:21 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/08 16:59:41 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first)
			{
				new = first->next;
				del(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include "ft_lstnew_bonus.c"
#include "ft_lstadd_back_bonus.c"
#include "ft_strlen.c"
#include "ft_strdup.c"
void	*my_function(void *content)
{
	char *dest = ft_strdup(content);
	if (dest == NULL)
		return NULL;
	*dest -= 32;
	return (dest);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *head = malloc(sizeof(t_list));
    t_list *second = malloc(sizeof(t_list));
    t_list *third = malloc(sizeof(t_list));
	t_list *new_list;

	head->content = malloc(sizeof(char) + 5);    
	head->next = second;
    second->content = malloc(sizeof(char) + 5);
    second->next = third;
    third->content = malloc(sizeof(char) + 5);
    
	strcpy(head->content, "a");
	strcpy(second->content, "b");
	strcpy(third->content, "c");

	printf("Contenido del primer nodo: %c \n", *(char *)head->content);
	printf("Contenido del segundo nodo: %c \n", *(char *)second->content);
	printf("Contenido del tercer nodo: %c \n", *(char *)third->content);

	new_list = ft_lstmap(head, &my_function, del);
	t_list *curent = new_list;

	printf("------------------------------\n");
	printf("Contenido del primer nodo: %s \n", (char *)curent->content);
	curent = curent->next;
	printf("Contenido del segundo nodo: %s \n", (char *)curent->content);
	curent = curent->next;
	printf("Contenido del tercer nodo: %s \n", (char *)curent->content);
	ft_lstclear(&new_list, del);
	ft_lstclear(&head, del);

	return (0);
}
*/
