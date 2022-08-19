/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:19:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/08/19 02:21:56 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write;
# include <stdlib.h> // exit, malloc, free;
# include <stdio.h> // DELETAR OS PRINTF!!!
# include "defs.h"

void		add_to_mv(int move, t_pushswap_data *ps_data);
int			case01(t_pushswap_data *ps_data);
int			case02(t_pushswap_data *ps_data);
int			case03(t_pushswap_data *ps_data);
int			calc_moves_quant(int best_index, int stack_sz);
int			check_arguments(char *argv[]);
int			check_if_last(t_stack *stack, int index);
int			check_invalid_chars(char *str);
void		check_repeated_numbers(t_pushswap_data *ps_data);
int			count_splits(char *argv);
void		create_moves_array(t_pushswap_data *ps_data);
int			create_stack(t_pushswap_data *ps_data);
void		free_list(t_pushswap_data *ps_data);
void		free_moves_array(char **moves);
void		free_pin(t_pushswap_data *ps_data);
void		free_print_list(t_movements *list);
void		freedom(t_pushswap_data *ps_data);
void		freexit(void *ptr, int exit_code);
long int	ft_atolong(const char *str);
int			ft_isnumber(int c);
int			ft_isspace(const char c);
long int	ft_atolong(const char *str);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char *s, char c);
char		*ft_strdup(const char *s1);
int			ft_strlen(const char *s);
int			get_best_a(t_pushswap_data *ps_data, t_svb self);
int			get_best_to_mv(t_pushswap_data *ps_data, t_svb self);
int			get_last_index(t_stack *stack);
void		get_lut(t_pushswap_data *data, char *argv[]);
int			get_lut_from(int best_x, t_stack *stack_x);
int			move_best_a(t_pushswap_data *ps_data, t_svb svb);
int			move_best_b(t_pushswap_data *ps_data, t_svb svb);
int			get_moves_to_pa(int a_index, int b_index, t_svb self);
void		get_stack_index(t_pushswap_data *ps_data);
int			get_stack_size(t_stack *stack);
int			i_should_rrr(t_pushswap_data *ps_data);
void		ifreexit(void *ptr_to_check, void *ptr_to_free, int exit_code);
void		index_to_data(t_pushswap_data *ps_data);
void		init_data(t_pushswap_data *ps_data, int in_nbr, char *argv[]);
t_svb		init_svb(t_pushswap_data *ps_data);
int			is_movable(int b_index, t_pushswap_data *ps_data);
int			lcs(t_lis *lis, t_pushswap_data *ps_data);
void		mv(int mv, t_pushswap_data *ps_data);
void		mv_pa(t_pushswap_data *ps_data);
void		mv_pb(t_pushswap_data *ps_data);
void		mv_ra(t_pushswap_data *ps_data, int log_mv);
void		mv_rb(t_pushswap_data *ps_data, int log_mv);
void		mv_rr(t_pushswap_data *ps_data);
void		mv_rra(t_pushswap_data *ps_data, int log_mv);
void		mv_rrb(t_pushswap_data *ps_data, int log_mv);
void		mv_rrr(t_pushswap_data *ps_data);
void		mv_sa(t_pushswap_data *ps_data, int log_mv);
void		mv_sb(t_pushswap_data *ps_data, int log_mv);
void		mv_ss(t_pushswap_data *ps_data);
void		pin_to_data(t_pushswap_data *ps_data);
int			populate_stack(t_pushswap_data *ps_data);
void print_list(t_stack *head_a); // DELETAR!
void		print_mv(t_movements *mv_to_print);
void		rr_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data);
void		rrrr_till_bot(t_stack *stack, int index, t_pushswap_data *ps_data);
void		set_pin(t_pushswap_data *ps_data);
void		sort_lut(t_pushswap_data *ps_data);
int			sort_radix(t_pushswap_data *ps_data);
void		sort_three(t_pushswap_data *ps_data);
void		sort_two(t_pushswap_data *ps_data);
void		sort_vb(t_pushswap_data *ps_data);
int			stack_is_indexed(t_stack *stack);
int			push_swap(t_pushswap_data *ps_data);
void		update_stacks_data(t_pushswap_data *ps_data);
int			validate_inputs(int argc, char *argv[]);
int			validate_splits(char *str);

#endif
