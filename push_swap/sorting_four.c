/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:37:43 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 16:38:38 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sortedlst(t_lst *alst)
{
	t_lst 	*tmp;
	int		i;

	i = 0;
	tmp = alst;
	while (tmp->next != alst)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	top_is_second(t_lst **a, t_lst **b)
{
	push(a, b, 'b');
    if (!is_sortedlst(*a))
	    sort_list_of_three(a, 0, 2, 3);
	push(b, a, 'a');
	swap(a, b, 'a');
}

void	sort_list_of_four(t_lst **a, t_lst **b);

void	top_is_third(t_lst *a, t_lst *b)
{
	swap(&a, &b, 'a');
	sort_list_of_four(&a, &b);
}

void	sort_list_of_four(t_lst **a, t_lst **b)
{
	if ((*a)->index == 0)
	{
		push(a, b, 'b');
		sort_list_of_three(a, 1, 2, 3);
		push(b, a, 'a');
	}
	else if ((*a)->index == 1)
		top_is_second(a, b);
	else if ((*a)->index == 2)
		top_is_third(*a, *b);
	else if ((*a)->index == 3)
	{
		push(a, b, 'b');
		sort_list_of_three(a, 0, 1, 2);
		push(b, a, 'a');
		rotate(a, b, 'a');
	}
}
