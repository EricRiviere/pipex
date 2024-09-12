/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:57:41 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/08 16:58:04 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <string.h>

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	char str[] = "hola hola!";
	
	if (node == NULL)
		printf("Error al crear el nodo");
	
	node->content = malloc(sizeof(char) + 11);
	strcpy(node->content, str);
	node->next = NULL;

	printf("Contenido del nodo: %s \n", (char *)node->content);

	ft_lstdelone(node, del);
	return (0);
}
*/
