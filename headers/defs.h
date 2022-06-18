/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:17:16 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/17 21:48:03 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H


typedef struct		s_stack
{
	int				num;
	int				index;
	int				stack_order;
	unsigned char	is_indexed;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

typedef struct		s_pushswap_data
{
	int				exit_code;
	int				*lut;
	int				ele_count;
	struct s_stack	*head_a;
	struct s_stack	*end_a;
	struct s_stack	*head_b;
	struct s_stack	*end_b;
} t_pushswap_data;

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define PSERROR	"Error\n"

#endif
