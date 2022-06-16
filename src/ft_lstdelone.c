/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:07:37 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/16 09:46:57 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del != NULL && lst != NULL)
	{
		del((*lst).content);
		free(lst);
		lst = 0;
	}
	return (void)(0);
}
