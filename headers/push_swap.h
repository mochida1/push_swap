/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:19:18 by hmochida          #+#    #+#             */
/*   Updated: 2022/06/23 12:41:37 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // read, write;
# include <stdlib.h> // exit, malloc, free;
# include <stdio.h> // DELETAR OS PRINTF!!!
# include "defs.h"

void		add_to_mv(int move, t_pushswap_data *ps_data);
int			check_arguments(char *argv[]);
int			check_invalid_chars(char *str);
void		check_repeated_numbers(t_pushswap_data *ps_data);
int			count_splits(char *argv);
void		create_moves_array(t_pushswap_data *ps_data);
int			create_stack(t_pushswap_data *ps_data);
void		free_list(t_pushswap_data *ps_data);
void		free_moves_array(char **moves);
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
void		get_lut(t_pushswap_data *data, char *argv[]);
void		get_stack_index(t_pushswap_data *ps_data);
void		ifreexit(void *ptr_to_check, void *ptr_to_free, int exit_code);
void		init_data(t_pushswap_data *ps_data, int in_nbr, char *argv[]);
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
int			populate_stack(t_pushswap_data *ps_data);
void print_list(t_stack *head_a); // DELETAR!
void		print_mv(t_movements *mv_to_print);
void		sort_lut(t_pushswap_data *ps_data);
void		sort_three(t_pushswap_data *ps_data);
void		sort_two(t_pushswap_data *ps_data);
t_movements	*push_swap(t_pushswap_data *ps_data);
void		update_stacks_data(t_pushswap_data *ps_data);
int			validate_inputs(int argc, char *argv[]);
int			validate_splits(char *str);

#endif
