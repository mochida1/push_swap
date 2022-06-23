/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:54:08 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/23 12:20:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
**1 2 3 -> ok;
**1 3 2 -> SWAP -> 312 -> RA;
**2 1 3 -> SWAP;
**2 3 1 -> RRA;
**3 1 2 -> RA;
**3 2 1 -> SWAP -> 231 -> RRA;
*/
static	int	like_jagger(int *indexes, int *lut)
{
	if (indexes[0] == lut[0] && indexes[1] == lut[1] && indexes[2] == lut[2])
		return (1);
	if (indexes[0] == lut[0] && indexes[1] == lut[2] && indexes[2] == lut[1])
		return (2);
	if (indexes[0] == lut[1] && indexes[1] == lut[0] && indexes[2] == lut[2])
		return (3);
	if (indexes[0] == lut[1] && indexes[1] == lut[2] && indexes[2] == lut[0])
		return (4);
	if (indexes[0] == lut[2] && indexes[1] == lut[0] && indexes[2] == lut[1])
		return (5);
	return (6);
}

static void	three_moves(int moves, t_pushswap_data *ps_data)
{
	if (moves == 1)
		return ;
	if (moves == 2)
	{
		mv(SA, ps_data);
		mv(RA, ps_data);
	}
	if (moves == 3)
		mv(SA, ps_data);
	if (moves == 4)
		mv(RRA, ps_data);
	if (moves == 5)
		mv(RA, ps_data);
	if (moves == 6)
	{
		mv(SA, ps_data);
		mv(RRA, ps_data);
	}
}

static int	*get_indexes(t_stack *stack)
{
	t_stack	*temp;
	int		*ret;
	int		i;

	i = 0;
	temp = stack;
	ret = malloc (sizeof(int) * 3);
	while (i < 3)
	{
		ret[i++] = temp->num;
		temp = temp->next;
	}
	return (ret);
}

void	sort_three(t_pushswap_data *ps_data)
{
	int	*indexes;
	int	moves;

	get_stack_index(ps_data);
	indexes = get_indexes(ps_data->head_a);
	moves = like_jagger(indexes, ps_data->lut);
	three_moves(moves, ps_data);
	free(indexes);
}