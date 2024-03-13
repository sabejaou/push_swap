/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:00:04 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 17:00:13 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_lst 	*tmp;
	int		i;

	i = 0;
	tmp = stack->alst;
	if (stack->blst)
		return (0);
	while (tmp->next != stack->alst)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	if (tmp->index != i)
			return (0);
	return (1);
}

void	ft_sort(t_stack *stack)
{
	int size = stack->nbelems + 1;
	int max_num = size - 1;
	int max_bits = 0;
	int		i;
	int		j;

	i = -1;
	size = ft_lstcirc_size(stack->alst);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((stack->alst->index >> i) & 1) == 1)
				rotate(&stack->alst, NULL, 'a');
			else
				push(&stack->alst, &stack->blst, 'b');
		}
		while (stack->blst)
			push(&stack->blst, &stack->alst, 'a');
	}
}

void	ft_littlesort(t_stack *stack)
{
	if (stack->nbelems == 1)
		if (stack->alst->index > stack->alst->next->index)
			rotate(&stack->alst, NULL, 'a');
	if (stack->nbelems == 2)
		sort_list_of_three(&stack->alst, 0, 1, 2);
	if (stack->nbelems == 3)
		sort_list_of_four(&stack->alst, &stack->blst);
	if (stack->nbelems == 4)
		sort_list_of_five(&stack->alst, &stack->blst);
}