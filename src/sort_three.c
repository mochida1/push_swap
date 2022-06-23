/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:54:08 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/22 21:33:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static	int	like_jagger(int *indexes, int *lut)
{

}

static void	three_moves(int moves, t_pushswap_data *ps_data)
{
	return ;
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
	moves = like_jagger()
	three_moves(moves, ps_data);
	free(indexes);
}