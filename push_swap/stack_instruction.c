/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:10:45 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 16:19:09 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **a, t_lst **b, char abr)
{
	if (abr == 'a' || abr == 'r')
		*a = (*a)->next;
	else if (abr == 'b' || abr == 'r')
		*b = (*b)->next;
	printf("r%c\n", abr);
}

void	reverse_rotate(t_lst **a, t_lst **b, char abr)
{
	if (abr == 'a' || abr == 'r')
		*a = (*a)->prev;
	else if (abr == 'b' || abr == 'r')
		*b = (*b)->prev;
	printf("rr%c\n", abr);
}

void	push(t_lst **fromlst, t_lst **tolst, char ab)
{
	t_lst	*node;

	node = *fromlst;
	if (node->next == node)
		*fromlst = NULL;
	if (node->next != node)
	{
		(*fromlst)->prev->next = (*fromlst)->next;
		(*fromlst)->next->prev = (*fromlst)->prev;
		*fromlst = (*fromlst)->next;
	}
	node->next = node;
	node->prev = node;
	*tolst = ft_lstcirc_addf(tolst, node);
	printf("p%c\n", ab);
}

void	swap(t_lst **a, t_lst **b, char abs)
{
    t_lst *tnode;
    
	if (abs == 'a' || abs == 's')
	{
        tnode = (*a)->next;
        (*a)->next = tnode->next;
        tnode->next->prev = *a;
        tnode->prev = (*a)->prev;
        (*a)->prev->next = tnode;
        (*a)->prev = tnode;
        tnode->next = *a;
        *a = tnode;
	}
	if (abs == 'b' || abs == 's')
	{
		tnode = (*b)->next->next;
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		(*b)->prev = (*b)->next;
		(*b)->next->next = (*b);
		(*b)->next = tnode;
		*b = tnode;
	}
	printf("s%c\n", abs);
}