/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:41:34 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/03 12:41:35 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_pb(t_stack *stack)
{
	t_nbr *tmp;

	if (stack && stack->a)
	{
		tmp = stack->b;
		stack->b = stack->a;
		stack->a = stack->a->next;
		stack->b->next = tmp;
		stack->size_a--;
		stack->size_b++;
		write(1, "pb\n", 3);
	}
}

void	ft_pa(t_stack *stack)
{
	t_nbr *tmp;

	if (stack && stack->b)
	{
		tmp = stack->a;
		stack->a = stack->b;
		stack->b = stack->b->next;
		stack->a->next = tmp;
		stack->size_a++;
		stack->size_b--;
		write(1, "pa\n", 3);
	}
}
