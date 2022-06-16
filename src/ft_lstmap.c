/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:03:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 09:46:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmplast;

	tmp = f(lst);
	tmplast = f(lst);
	if (!tmp || !f)
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
		tmplast->next = f(lst);
		if (tmplast->next == NULL)
			return (NULL);
		tmplast = tmplast->next;
	}
	return (tmp);
}
