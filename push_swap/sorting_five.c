/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:36:21 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 16:48:24 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_zero(t_lst **a, t_lst **b)
{
	if ((*a)->index == 0)
		push(a, b, 'b');
	else if ((*a)->next->index == 0)
	{
		swap(a, b, 'a');
		push(a, b, 'b');
	}
	else if ((*a)->next->next->index == 0)
	{
		rotate(a, b, 'a');;
		rotate(a, b, 'a');;
		push(a, b, 'b');
	}
	else if ((*a)->next->next->next->index == 0)
	{
		reverse_rotate(a, NULL, 'a');;
		reverse_rotate(a, NULL, 'a');;
		push(a, b, 'b');
	}
	else if ((*a)->next->next->next->next->index == 0)
	{
		reverse_rotate(a, NULL, 'a');;
		push(a, b, 'b');
	}
}

void	pb_one(t_lst **a, t_lst **b)
{
	if ((*a)->index == 1)
		push(a, b, 'b');
	else if ((*a)->next->index == 1)
	{
		swap(a, b, 'a');
		push(a, b, 'b');
	}
	else if ((*a)->next->next->index == 1)
	{
		rotate(a, b, 'a');;
		rotate(a, b, 'a');;
		push(a, b, 'b');
	}
	else if ((*a)->next->next->next->index)
	{
		reverse_rotate(a, NULL, 'a');;
		push(a, b, 'b');
	}
}

void	sort_list_of_five(t_lst **a, t_lst **b)
{
	pb_zero(a, b);
	pb_one(a, b);
    if (!is_sortedlst(*a))
	    sort_list_of_three(a, 2, 3, 4);
	push(b, a, 'a');
	push(b, a, 'a');
}