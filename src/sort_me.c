/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:37:36 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/04 19:16:46 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	stack_is_sorted(t_stack *head_a, int ele_count)
{
	t_stack *temp;
	int		flag;
	int		count;

	temp = head_a;
	flag = 0;
	count = 0;
	while (temp)
	{
		if (temp->num > temp->next->num && !flag)
		{
			flag = 1;
			temp = temp->next;
			count++;
			continue ;
		}
		if (temp->num < temp->next->num)
		{
			temp = temp->next;
			count++;
		}
		break;
	}
	return (count == ele_count);
}

static int is_near_end(t_stack *head_x, int ele_count)
{
	int		count;
	t_stack	*temp;

	temp = head_x;
	count = 0;
	while (temp)
	{
		if (temp->next && (temp->num < temp->next->num))
			{
				temp = temp->next;
				count ++;
			}
		else
			break;
	}
	if (count > ele_count)
		return (1);
	return (0);
}

static int	case_6(t_pushswap_data *ps_data)
{
	printf ("6\n");
	if (ps_data->head_b)
		return (0);
	else if (stack_is_sorted(ps_data->head_a, ps_data->ele_count))
	{
		if (is_near_end(ps_data->head_a, ps_data->ele_count))
		{
			while (ps_data->head_a->num != ps_data->lut[0])
				mv(RA, ps_data);
			return (1);
		}
		else
		{
			while (ps_data->head_a->num != ps_data->lut[0])
				mv(RRA, ps_data);
			return (1);
		}
	}
	else
		return (0);
}

static int	case_5(t_pushswap_data *ps_data)
{
	printf ("5\n");
	if (!ps_data->head_a)
		return (0);
	mv(PB, ps_data);
	return (1);
}

/*
** se TOP_A estiver PINADO, RA
*/
static int	case_4(t_pushswap_data *ps_data)
{
	if (!ps_data->head_a)
		return (0);
	if (ps_data->head_a->is_indexed)
	{
	printf("num: %d\n", ps_data->head_a->num);
	printf ("4\n");
		mv(RA, ps_data);
		return (1);
	}
	return (0);
}

/*
** se existir STACK B o topo do STACK B for o elemento na LUT antes do elemento
** topo do STACK A na LUT, PUSH A;
*/
static int	case_3(t_pushswap_data *ps_data)
{
	if (!ps_data->head_b)
		return (0);
	if (ps_data->head_b->num < ps_data->head_a->num)
	{
		if ((ps_data->head_a->index) ==
			ps_data->head_b->index - 1)
			{
	printf ("3\n");
				ps_data->head_b->is_indexed = 1;
				mv(PA, ps_data);
				return (1);
			}
	}
	return (0);
}

/*
** caso TOP_A entre em ordem indexada e TOP_B não, SA
*/
static int	case_2(t_pushswap_data *ps_data)
{
	if (!ps_data->head_a)
		return (0);
	if	(ps_data->head_a->is_indexed)
		return (0);
	if (ps_data->head_a->num > ps_data->head_a->next->num)
		if (ps_data->head_a->index +1 == ps_data->head_a->next->index)
		{
		printf ("2\n");
			mv(SA, ps_data);
			return (1);
		}
	return (0);
}

/*
** Testa TOP_A e TOP_B: se TOP_A entrar em ordem crescente com um SWAP A e TOP_B
** entrar em ordem crescente com um SWAP B -> SS
*/
int	case_1(t_pushswap_data *ps_data)
{
	if (!ps_data->head_a || !ps_data->head_b)
		return (0);
	if	(ps_data->head_a->is_indexed)
		return (0);
	if (ps_data->head_a->num > ps_data->head_a->next->num &&
			ps_data->head_b->num > ps_data->head_b->next->num)
	{
	printf ("1\n");
		mv(SS, ps_data);
		return (1);
	}
	return (0);
}

void PRINT_PIN(t_pushswap_data *ps_data)
{
	t_pin *temp;

	temp = ps_data->pin_head;
	printf (">>>>");
	while (temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf ("<<<<\n");
}

/*
** initializes all is_indexed variables to reflect their right status;
*/
void	pin_to_data(t_pushswap_data *ps_data)
{
	t_pin 	*pintemp;
	t_stack	*stack;

	stack = ps_data->head_a;
	pintemp = ps_data->pin_head;
	while (stack)
	{
		while (pintemp)
		{
			if (stack->num == pintemp->num)
				stack->is_indexed = 1;
			pintemp = pintemp->next;
		}
		pintemp = ps_data->pin_head;
		stack = stack->next;
	}
}

/*
** set's all indexes in the stack to their right place.
*/
void	index_to_data(t_pushswap_data *ps_data)
{
	t_stack *temp;

	int	i;
	i = 0;
	temp = ps_data->head_a;
	while (temp)
	{
		while (i < ps_data->ele_count)
		{
			if (temp->num == ps_data->lut[i])
				temp->index = i;
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}

/*
** sort case for more than three elements;
*/
void	sort_me(t_pushswap_data *ps_data)
{
	int	run;

	run = 1;
	set_pin(ps_data);
	pin_to_data(ps_data);
	index_to_data(ps_data);
	print_list(ps_data->head_a);
	while (run)
	{
		update_pins(ps_data);
		if (case_1(ps_data))
			continue ;
		else if (case_2(ps_data))
			continue ;
		else if (case_3(ps_data))
			continue ;
		else if (case_4(ps_data))
			continue ;
		else if (case_5(ps_data))
			continue ;
		else if (case_6(ps_data))
			continue ;
		else
			run = 0;
	}
}
