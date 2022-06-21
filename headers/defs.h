/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/21 17:10:58 by hmochida         ###   ########.fr       */
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
	char **moves;
} t_pushswap_data;

typedef struct		s_movements
{
	char *movement;
	struct s_movements	*next;
} t_movements;

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define PSERROR	"Error\n"
#define SA	0
#define SB	1
#define SS	2
#define RA		3
#define RB		4
#define RR		5
#define RRA		6
#define RRB		7
#define RRR		8
#define PB		9
#define PA		10

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
