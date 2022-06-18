/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:49:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 15:10:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

/*
** If shit goes sideways, frees all pointers allocated so far and exits.
** It works, trust me.
*/
static void	free_some_pointers(t_pushswap_data *ps_data)
{
	t_stack *temp = ps_data->head_a;

	while (ps_data->head_a)
	{
		temp = ps_data->head_a;
		ps_data->head_a = ps_data->head_a->next;
		free (temp);
		temp = NULL;
	}
	free(ps_data->lut);
	free(ps_data);
	ft_putstr_fd(PSERROR, 2);
	exit (1);
}

/*
** Creates a new node on the list.
*/
static t_stack	*ft_lstnew(t_stack *prev)
{
	t_stack	*fresh;

	fresh = malloc(sizeof(t_stack));
	if (!(fresh))
		return (0);
	fresh->prev = prev;
	fresh->next = NULL;
	return (fresh);
}

/*
** Creates the stack. yeah, really.
*/
int	create_stack(t_pushswap_data *ps_data)
{
	int i;
	t_stack *temp;

	i = 1;
	ps_data->head_a = ft_lstnew (NULL);
	temp = ps_data->head_a;
	while (i < ps_data->ele_count)
	{
		temp->next = ft_lstnew (temp);
		if (!temp->next)
			free_some_pointers (ps_data);
		temp = temp->next;
		i++;
	}
	ps_data->end_b = temp;
	populate_stack(ps_data);
	return (0);
}
