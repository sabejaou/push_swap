/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:17 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/12 17:36:49 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_skip_sp_nb(char *av, int *i)
{
    int j;

    j = 0;
	while (av[j] && (av[j] == ' ' || (av[j] >= 9 && av[j] <= 13)))
		j++;
	if ((av[j] == '+' || av[j] == '-'))
		*i = -1;
    if (av[j] < '0' || av[j] > '9')
		j++;
	while (av[j] >= '0' && av[j] <= '9')
		j++;
    printf("i=%d arg[i]:%c\n", *i, av[j]);
    if ((av[j] != ' ' && (av[j] < 9 || av[j] > 13)) && av[j])
        *i = -1;
    printf("i=%d\n", *i);
	while (av[j] && (av[j] == ' ' || (av[j] >= 9 && av[j] <= 13)))
		j++;
    return (j);
}

t_lst	*ft_arg_to_lst(char *arg, t_stack **stack)
{
	int	i;

	i = 0;
	if (!arg)
		return ((*stack)->alst);
	while (arg[i])
	{
		(*stack)->alst = ft_lstcirc_addb(&(*stack)->alst, ft_lstcirc_new(atoi(arg + i)));
		if (!(*stack)->alst)
			return (NULL);
		i += ft_skip_sp_nb(arg + i, &i);
        printf("i=%d arg[i]:%c\n", i, arg[i]);
        if (i == -1)
        {
            ft_lstcirc_clear(&(*stack)->alst);
            return (NULL);
        }
	}
	return ((*stack)->alst);
}

int	ft_check_args(char **av)
{
	int	i;
	int	j;
	int	digit;

	digit = 0;
	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if ((av[i][j] != '+' && av[i][j] != '-' && av[i][j] != ' '
				&& (av[i][j] < 9 || av[i][j] > 13) && (av[i][j] < '0'
				|| av[i][j] > '9')) || (((av[i][j] == '+'
				|| av[i][j] == '-') && !av[i][j + 1])))
				return (1);
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				digit++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!digit)
		return (1);
	return (0);
}