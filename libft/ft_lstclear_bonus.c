/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:21:27 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/30 17:20:11 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*last;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		del(curr->content);
		last = curr;
		curr = curr->next;
		free(last);
	}
	*lst = NULL;
}
