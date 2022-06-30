/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:50:52 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/30 15:45:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	add_to_pin(t_pin *ret, int t_num)
{
	t_pin *temp;

	temp = ret;
	temp->next = malloc (sizeof(t_pin));
	temp = temp->next;
	temp->num = t_num;
}

/*
** iterate the list circularly.
*/
static void	increment_list(t_stack *temp, t_stack *head_a)
{
	if (temp->next)
		temp = temp->next;
	else
		temp = head_a;
}

/*
**
*/
static void	iterate_list(int k, t_pushswap_data *ps_data)
{
	while (k--)
	{
		if (t_num < temp->num)
		{
			add_to_pin(ret, t_num);
			increment_list(temp, ps_data->head_a);
		}
		increment_list(temp, ps_data->head_a);
		t_num = temp->num;
	}
}

/*
** get the longest incresing subsequence starting on a given element of the 
** head_a list;
*/
static t_pin	*get_pin(t_pushswap_data *ps_data, int i)
{
	int		k;
	int		t_num;
	t_stack	*temp;
	t_pin	*ret;

	temp = ps_data->head_a;
	t_num = ps_data->head_a->num;
	k = ps_data->ele_count;
	while (i--) // chega no elemento em que queremos começar
		increment_list(temp, ps_data->head_a);
	ret = init_ret(ret, temp->num);
	iterate_list();
	return (ret);
}

/*
** sets ps_data->pin to the largest sequence of already sorted numbers in the
** arguments.
*/
void	set_pin(t_pushswap_data *ps_data)
{
	int		i;
	int		temp_sz;
	t_pin	*temp;

	i = 0;
	while (i < ps_data->ele_count)
	{
		temp = get_pin(ps_data, i);
		temp_sz = count_pin_list(temp);
		if (temp_sz >= ps_data->pin_size && ps_data->pin != temp)
		{
			free_pin(ps_data->pin);
			ps_data->pin = temp;
			ps_data->pin_size = temp_sz;
		}
		else
		{
			free_pin(temp);
			temp = NULL;
		}
		i++;
	}
}
