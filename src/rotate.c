/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:42:02 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/03 12:42:03 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_rr(t_stack *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}

void	ft_rb(t_stack *stack)
{
	t_nbr *tmp;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack->b;
		stack->b = stack->b->next;
		tmp->next->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_ra(t_stack *stack)
{
	t_nbr *tmp;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack->a;
		stack->a = stack->a->next;
		tmp->next->next = NULL;
		write(1, "ra\n", 3);
	}
}
