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

static int	case_4(t_pushswap_data *ps_data)
{
	if (!ps_data->head_a)
		return (0);
	if (ps_data->head_a->is_indexed)
	{
	printf ("4\n");
		mv(RA, ps_data);
		return (1);
	}
	return (0);
}


static int	case_3(t_pushswap_data *ps_data)
{
	printf ("3\n");
	if (!ps_data->head_b)
		return (0);
	if (ps_data->head_b->num > ps_data->head_a->num)
	{
		if (get_lut_index((ps_data->head_a->num + 1) , ps_data) ==
			get_lut_index(ps_data->head_b->num, ps_data))
			{
				mv(PA, ps_data);
				return (1);
			}
	}
	return (0);
}

static int	case_2(t_pushswap_data *ps_data)
{
	printf ("2\n");
	if (!ps_data->head_a)
		return (0);
	if (ps_data->head_a->num > ps_data->head_a->next->num)
	{
		mv(SA, ps_data);
		return (1);
	}
	return (0);
}

/*
**
*/
int	case_1(t_pushswap_data *ps_data)
{
	printf ("1\n");
	if (!ps_data->head_a || !ps_data->head_b)
		return (0);
	if (ps_data->head_a->num > ps_data->head_a->next->num &&
			ps_data->head_b->num > ps_data->head_b->next->num)
	{
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
** sort case for more than three elements;
*/
void	sort_me(t_pushswap_data *ps_data)
{
	int	run;

	run = 1;
	set_pin(ps_data);
	pin_to_data(ps_data);
	while (run)
	{
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
