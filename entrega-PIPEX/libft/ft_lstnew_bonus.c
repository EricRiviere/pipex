/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:23 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/08 16:51:34 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*create_node = ft_lstnew("new node created");

	if (create_node != NULL)
	{
		printf("Success!\n");
		printf("Inside the node = %s \n", (char *)create_node->content);
	}
	else
		printf("Something is wrong.");
	free(create_node);
	return (0);
}
*/
