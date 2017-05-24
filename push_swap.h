/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:04:58 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 20:06:54 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define STACK_I(x, y) (get_ith_stack(*x, y))->value

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
	int				status;
	char			*color;
}					t_stack;

typedef struct		s_instruction
{
	char			*command;
	int				(*f)(t_stack **a, t_stack **b);
}					t_instruction;

typedef struct		s_options
{
	int				fd;
	int				v;
	int				c;
	int				arg_index;
	int				count;
}					t_options;

t_stack				*parse(int argc, char **argv);

t_stack				*new_stack(int input);
void				destroy_stack(t_stack **stack);
t_stack				*pop(t_stack **stack);
int					push(t_stack **stack, t_stack *element);

int					swap(t_stack **stack);
int					rotate(t_stack **stack);
int					reverse_rotate(t_stack **stack);

int					stack_is_sorted(t_stack *stack);
int					stack_length(t_stack *stack);
int					section_length(t_stack *stack);
t_stack				*get_ith_stack(t_stack *stack, int index);

int					stack_iter(t_stack *stack, int (*f)(t_stack *, void *),
					void *data);
int					is_different(t_stack *element, void *comparison);
int					is_greater_than(t_stack *element, void *comparison);
int					is_lower_than(t_stack *element, void *comparison);
int					is_equal(t_stack *element, void *comparison);
int					if_greater_or_equal_update(t_stack *element,
					void *comparison);
int					is_not_fixed(t_stack *element, void *comparison);
int					set_as_sorted(t_stack *element, void *data);
int					set_as_unsorted(t_stack *element, void *data);
void				stack_sorted_status(t_stack *stack);

int					perform_instruction(t_stack **a, t_stack **b,
					char *instruction);
int					perform_print_instruction(t_stack **a, t_stack **b,
					char *instruction);
int					sa(t_stack **a, t_stack **b);
int					sb(t_stack **a, t_stack **b);
int					ss(t_stack **a, t_stack **b);
int					pa(t_stack **a, t_stack **b);
int					pb(t_stack **a, t_stack **b);
int					ra(t_stack **a, t_stack **b);
int					rb(t_stack **a, t_stack **b);
int					rr(t_stack **a, t_stack **b);
int					rra(t_stack **a, t_stack **b);
int					rrb(t_stack **a, t_stack **b);
int					rrr(t_stack **a, t_stack **b);

t_list				*new_move(t_stack **a, t_stack **b, t_list **moves,
					int(*f)(t_stack **a, t_stack **b));
t_list				*join_lst(t_list *first, t_list *second);

t_list				*trim_list_moves(t_list **moves);

t_list				*sort(t_stack **a, t_stack **b, t_list *moves,
					t_options *options);
t_list				*do_swaps(t_stack **a, t_stack **b, t_list *moves);
t_list				*bubble_sort_rev_a(t_stack **a, t_stack **b, t_list *moves);

int					find_median(t_stack *stack);
t_list				*divide_a_to_b(t_stack **a, t_stack **b, t_list *moves);
t_list				*divide_b_to_a(t_stack **a, t_stack **b, t_list *moves);

void				error_exit(char *message, t_stack *a, t_stack *b,
					t_list *moves);
void				print_stacks(t_stack *a, t_stack *b, t_options *options);
void				print_list_moves(t_list *moves, int fd);

#endif
