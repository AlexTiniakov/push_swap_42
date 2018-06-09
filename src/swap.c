/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:41:19 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/03 12:41:20 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_ss(t_stack *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}

void	ft_sb(t_stack *stack)
{
	t_nbr *tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		tmp->next = stack->b->next;
		stack->b->next = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_sa(t_stack *stack)
{
	t_nbr *tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		tmp->next = stack->a->next;
		stack->a->next = tmp;
		write(1, "sa\n", 3);
	}
}
