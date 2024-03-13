/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:01:43 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:58 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstscirc_print(t_lst **a, t_lst **b)
{
	t_lst *elem;

	elem = *a;
	printf("\nLST A\n");
	while (elem && elem->next != *a)
	{
		printf("\nPREV I:%d > I:%d > NEXT I:%d | INDEX:%d | LST INDEX:%d\n\n", ((elem->prev)->nb), elem->nb, (elem->next)->nb, elem->index, elem->lst_index);
		elem = elem->next;
	}
	if (elem)
		printf("\nPREV I:%d > I:%d > NEXT I:%d | INDEX:%d | LST INDEX:%d\n\n", ((elem->prev)->nb), elem->nb, (elem->next)->nb, elem->index, elem->lst_index);
	if (!*b)
	{
		printf("\nLST B = NULL\n");
		return;
	}
	printf("\n\nLST B\n");
	elem = *b;
	while (elem->next != *b)
	{
		printf("\nPREV I:%d > I:%d > NEXT I:%d | INDEX:%d\n\n", ((elem->prev)->nb), elem->nb, (elem->next)->nb, elem->index);
		elem = elem->next;
	}
	printf("\nPREV I:%d > I:%d > NEXT I:%d | INDEX:%d\n\n", ((elem->prev)->nb), elem->nb, (elem->next)->nb, elem->index);
}
