/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:39:35 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/03 16:39:38 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		is_sort(t_nbr *a)
{
	t_nbr	*beg;

	beg = a;
	while (beg->next)
	{
		if (beg->nbr > beg->next->nbr)
			return (0);
		beg = beg->next;
	}
	return (1);
}

void	get_min(t_stack *stack, int *min)
{
	t_nbr	*tmp;
	int		i;

	tmp = stack->a;
	min[0] = tmp->nbr;
	i = 1;
	while (tmp && tmp->next)
	{
		if (min[0] > tmp->next->nbr)
		{
			min[0] = tmp->next->nbr;
			min[1] = i <= stack->size_a / 2 + stack->size_a % 2 ? 1 : 0;
			min[1] = i == 2 && stack->size_a == 5 ? 1 : min[1];
		}
		i++;
		tmp = tmp->next;
	}
}

void	ft_sort_buble(t_stack *stack)
{
	int min[2];

	while (stack->a && stack->a->next && !is_sort(stack->a))
	{
		get_min(stack, (int *)&min[0]);
		if (min[0] == stack->a->nbr)
			ft_pb(stack);
		else
		{
			while (min[0] != stack->a->nbr)
				min[1] ? ft_ra(stack) : ft_rra(stack);
			if (!is_sort(stack->a))
				ft_pb(stack);
		}
	}
	while (stack->b)
		ft_pa(stack);
}
