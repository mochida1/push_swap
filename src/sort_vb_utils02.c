/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vb_utils02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:06:46 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 01:20:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	get_moves_to_pa(int a_index, int b_index, t_svb self)
{
	int	moves_a;
	int	moves_b;

	moves_a = -1;
	moves_b = -1;
	if (a_index <= self.size_a / 2)
		moves_a = a_index;
	else
		moves_a = self.size_a - a_index;
	if (b_index <= self.size_b / 2)
		moves_b = b_index;
	else
		moves_b = self.size_b - b_index;
	return (moves_a + moves_b);
}

/*
** gets the index of the !!STACK!! of the best element to move
*/
int	get_best_to_mv(t_pushswap_data *ps_data, t_svb self)
{
	int	vars[4];

	vars[0] = 0;
	vars[2] = -1;
	vars[3] = -1;
	while (vars[0] < self.size_b)
	{
		vars[1] = is_movable(vars[0], ps_data);
		if (vars[1] >= 0)
		{
			if (vars[2] < 0)
			{
				vars[2] = get_moves_to_pa(vars[1], vars[0], self);
				vars[3] = vars[0];
			}
			else if (vars[2] < get_moves_to_pa(vars[1], vars[0], self))
			{
				vars[3] = vars[0];
				vars[2] = get_moves_to_pa(vars[1], vars[0], self);
			}
		}
		vars[0]++;
	}
	return (vars[3]);
}

int	get_best_a(t_pushswap_data *ps_data, t_svb self)
{
	return (is_movable(self.best_b, ps_data));
}

int	calc_moves_quant(int best_index, int stack_sz)
{
	if (best_index < stack_sz / 2)
		return (best_index);
	else
		return (stack_sz - best_index);
}

int	get_lut_from(int best_x, t_stack *stack_x)
{
	int		i;
	t_stack	*temp;

	temp = stack_x;
	i = 0;
	while (i != best_x)
	{
		temp = temp->next;
		i++;
	}
	return (temp->index);
}
