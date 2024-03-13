/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:00:01 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 17:09:03 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_lst *alst)
{
    int max = alst->nb;
    t_lst *current = alst->next;
    while (current != alst)
    {
        if (current->nb > max)
            max = current->nb;
        current = current->next;
    }
    return max;
}

void	ft_reindex(t_lst **alst, size_t nbelems)
{
	int	i;
	t_lst *smaller;
	t_lst *node;

	i = 0;
	while (i <= nbelems)
	{
		node = *alst;
		smaller = *alst;
		while (smaller->index >= 0)
		{
			smaller = smaller->next;
			node = node->next;
		}
		while (node->next != *alst)
		{
			if (node->nb < smaller->nb && node->index < 0)
				smaller = node;
			node = node->next;
		}
		if (node->nb < smaller->nb && node->index < 0)
				smaller = node;
		smaller->index = i++;
	}
}

int	ft_error()
{
	dprintf(2, "Error\n");
	return (-1);
}

int main(int ac, char **av)
{
	int	i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->nbelems = 0;
	if (ft_check_args(av))
		return (ft_error());
	(stack->alst) = NULL;
	stack->blst = NULL;
	i = 1;
	while (av[i])
	{
		(stack->alst) = ft_arg_to_lst(av[i], &stack);
		i++;
		if ((stack->alst) == NULL)
			return (ft_error());
	}
	stack->nbelems = ft_lstcirc_size(stack->alst) - 1;
	ft_reindex(&stack->alst, stack->nbelems);
	if (is_sorted(stack))
		return (0);
	if (stack->nbelems <= 4)
		ft_littlesort(stack);
	else
		ft_sort(stack);
	ft_lstscirc_print(&stack->alst, &stack->alst);
	ft_lstcirc_clear(&(stack->alst));
	free(stack);
	return (0);
}