/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/17 23:59:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/*
** num: is the argument received;
** index:
** stack_order: element number from head to bottom;
** is_indexed: 0 if it's not on PIN, 1 if PINned;
*/
typedef struct s_stack
{
	int					num;
	int					index;
	unsigned int		stack_order;
	unsigned char		is_indexed;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

/*
** struct holding shit to be used by the sorting algo
*/
typedef struct s_svb
{
	int	size_a;
	int	size_b;
	int	best_a;
	int	best_b;
	int	index_a;
	int	index_b;
	int	dist_a;
	int	dist_b;
}	t_svb;

/*
**
*/
typedef struct s_pin
{
	int					num;
	struct s_pin		*next;
}	t_pin;

typedef struct s_lis
{
	int					**lcs_t;
	int					*unsrt;
	int					*lcs_m;
	int					lcs_size;
}	t_lis;

/*
** exit_code: if exiting is needed, keeps the exit code to be used after frees;
** lut: sorted array of arguments
** pin_head: keeps the numbers wich are already sorted;
** ele_count: quantity of received elements(arguments) to be sorted;
** mv_to_print: stack of things to be printed;
** moves: keeps the strings of movements names;
*/
typedef struct s_pushswap_data
{
	int					exit_code;
	int					ele_count;
	int					pin_size;
	int					*lut;
	struct s_pin		*pin_head;
	struct s_stack		*head_a;
	struct s_stack		*end_a;
	struct s_stack		*head_b;
	struct s_stack		*end_b;
	struct s_movements	*mv_to_print;
	char				**moves;
}	t_pushswap_data;

typedef struct s_movements
{
	char				*movement;
	struct s_movements	*next;
}	t_movements;

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define PSERROR	"Error\n"
# define SA 0
# define SB 1
# define SS 2
# define RA 3
# define RB 4
# define RR 5
# define RRA 6
# define RRB 7
# define RRR 8
# define PB 9
# define PA 10

#endif
