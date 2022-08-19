/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:29:52 by coder             #+#    #+#             */
/*   Updated: 2022/08/19 23:35:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_bit(int largest_number, int i)
{
	return ((largest_number >> i) & 1);
}

int	msb(int largest_number)
{
	int	i;

	i = 31;
	while (check_bit(largest_number, i) != 1)
		i--;
	return (i);
}

int	is_crecent(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int		ret;

	temp = ps_data->head_a;
	ret = temp->index;
	temp = temp->next;
	while (temp)
	{
		if (ret < temp->index)
			return (0);
		ret = temp->index;
		temp = temp->next;
	}
	return (1);
}

void	move_zero(t_pushswap_data *ps_data, int i)
{
	int	j;

	j = 0;
	while (j < ps_data->ele_count)
	{
		if (check_bit(ps_data->head_a->index, i) == 0)
			mv(PB, ps_data);
		else
			mv(RA, ps_data);
		if (is_crecent(ps_data))
			break ;
		j++;
	}
}

int	get_largest_index(t_pushswap_data *ps_data)
{
	t_stack	*temp;
	int		ret;

	temp = ps_data->head_a;
	ret = 0;
	while (temp)
	{
		if (temp->index > ret)
			ret = temp->index;
		temp = temp->next;
	}
	return (ret);
}
