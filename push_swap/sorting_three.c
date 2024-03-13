/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:38:24 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 16:26:50 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_is_greater(t_lst **a, int smaller)
{
	if ((*a)->next->index == smaller)
		rotate(a, NULL, 'a');
	else
	{
		rotate(a, NULL, 'a');
		swap(a, NULL, 'a');
	}
}

void	top_is_median(t_lst **a, int smaller)
{
	if ((*a)->next->index == smaller)
		swap(a, NULL, 'a');
	else
		reverse_rotate(a, NULL, 'a');
}

void	top_is_smallest(t_lst **a)
{
	swap(a, NULL, 'a');
	rotate(a, NULL, 'a');
}

void	sort_list_of_three(t_lst **a, int smaller, int median, int greater)
{
	if ((*a)->index== greater)
		top_is_greater(a, smaller);
	else if ((*a)->index== median)
		top_is_median(a, smaller);
	else if ((*a)->index== smaller)
		top_is_smallest(a);
}
