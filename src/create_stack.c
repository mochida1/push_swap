/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:49:26 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/18 01:47:18 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

static void	free_some_pointers(t_pushswap_data *ps_data, t_stack **ptrs, int i)
{
	while (i >= 0)
	{
		free ptrs[i--];
	}
	free(ptrs);
	free(ps_data->lut);
	free(ps_data);
	ft_putstr_fd(PSERROR, 2);
	exit (1);
}

/*
** yes, it's that ugly.
*/
int	create_stack(t_pushswap_data *ps_data)
{
	t_stack **ptrs;
	int i;

	i = 0;
	ptrs = malloc (sizeof(t_stack *) * ps_data->ele_count + 1);
	ptrs[ps_data->ele_count] = NULL;
	while (i < ps_data->ele_count)
	{
		ptrs[i] = malloc (sizeof(t_stack));
		if (!ptrs[i])
			free_some_pointers(ps_data, ptrs, i);
		i++;
	}
	ps_data->head_a = ptrs[0];

	free (ptrs);
}
