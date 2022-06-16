/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:18:58 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 09:47:01 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	temp = *lst;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		temp->next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		temp = (*temp).next;
	}
	*lst = NULL;
}
