/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:33:00 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 15:34:48 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst  *ft_lstcirc_new(int	nb)
{
	t_lst	*new;
	
	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->score = 0;
	new->index = -1;
	new->nb = nb;
	return (new);
}

t_lst	*ft_lstcirc_addf(t_lst **alst, t_lst *node)
{
	if (!*alst)
		return (node);
	if (!node)
		return (NULL);
	if (*alst && (*alst)->next == *alst)
		(*alst)->next = node;
	node->prev = (*alst)->prev;
	(*alst)->prev->next = node;
	(*alst)->prev = node;
	node->next = *alst;
	*alst = node;
	return (*alst);
}

t_lst	*ft_lstcirc_addb(t_lst **alst, t_lst *node)
{
	if (!*alst)
		return (node);
	if (!node)
		return (NULL);
	if (*alst && (*alst)->next == *alst)
	{
		(*alst)->prev = node;
		(*alst)->next = node;
		node->prev = *alst;
		node->next = *alst;
	}
	else
	{
		node->next = *alst;
		node->prev = (*alst)->prev;
		(*alst)->prev->next = node;
		(*alst)->prev = node;
	}
	return (*alst);
}

void	ft_lstcirc_clear(t_lst **alst)
{
	t_lst	*node;
	t_lst	*tmp;

	node = (*alst)->next;
	while (node != *alst)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free (node);
}

int	ft_lstcirc_size(t_lst *lst)
{
	t_lst	*temp;
	int		count;

	if (!lst)
		return (0);
	temp = lst;
	count = 0;
	while (temp->next != lst)
    {
		count++;
		temp = temp->next;
	}
	return (++count);
}