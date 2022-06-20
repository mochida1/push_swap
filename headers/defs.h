/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/20 19:17:15 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H


typedef struct		s_stack
{
	int				num;
	int				index;
	unsigned int	stack_order;
	unsigned char	is_indexed;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

typedef struct		s_pushswap_data
{
	int				exit_code;
	int				*lut;
	int				*pin;
	int				ele_count;
	struct s_stack	*head_a;
	struct s_stack	*end_a;
	struct s_stack	*head_b;
	struct s_stack	*end_b;
	struct s_movements	*mv_to_print;
} t_pushswap_data;

typedef struct		s_movements
{
	char *movement;
	struct s_movements	*next;
} t_movements;

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define PSERROR	"Error\n"
#define SWAP_A	"swap a\n"
#define SWAP_B	"swap b\n"
#define SWAP_S	"swap s\n"
#define RA		"ra\n"
#define RB		"rb\n"
#define RR		"rr\n"
#define RRA		"rra\n"
#define RRB		"rrb\n"
#define RRR		"rrr\n"
#define PB		"pb\n"
#define PA		"pa\n"

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
