/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:11:22 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 17:30:37 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_lst
{
	struct s_lst  *prev;
	int     nb;
	int     score;
	int		index;
	int		lst_index;
	struct s_lst  *next;
} t_lst;

typedef struct s_stack
{
	t_lst *alst;
	t_lst *blst;
	size_t nbelems;
} t_stack;

// stack_instruction.c
void	rotate(t_lst **a, t_lst **b, char abr);
void	reverse_rotate(t_lst **a, t_lst **b, char abr);
void	push(t_lst **fromlst, t_lst **tolst, char ab);
void	swap(t_lst **a, t_lst **b, char abs);

// circlist_utils.c
t_lst  *ft_lstcirc_new(int	nb);
t_lst	*ft_lstcirc_addf(t_lst **alst, t_lst *node);
t_lst	*ft_lstcirc_addb(t_lst **alst, t_lst *node);
void	ft_lstcirc_clear(t_lst **alst);
int	ft_lstcirc_size(t_lst *lst);

// sorting_five.c
void	sort_list_of_five(t_lst **a, t_lst **b);

//sorting_four.c
void	sort_list_of_four(t_lst **a, t_lst **b);
int	    is_sortedlst(t_lst *alst);

// sorting_three.c
void	sort_list_of_three(t_lst **a, int smaller, int median, int greater);

//sorting.c
int	    is_sorted(t_stack *stack);
void	ft_sort(t_stack *stack);
void	ft_littlesort(t_stack *stack);

// args.c
int  ft_skip_sp_nb(char *av, int *i);
t_lst	*ft_arg_to_lst(char *arg, t_stack **stack);
int	    ft_check_args(char **av);

// debug.c
void	ft_lstscirc_print(t_lst **a, t_lst **b);

#endif