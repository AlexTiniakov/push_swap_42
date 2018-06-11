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
	char *str;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack->b;
		stack->b = stack->b->next;
		tmp->next->next = NULL;
		str = stack->rez;
		stack->rez = ft_strjoin(stack->rez, "rb\n");
		free(str);
	}
}

void	ft_ra(t_stack *stack)
{
	t_nbr *tmp;
	char *str;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack->a;
		stack->a = stack->a->next;
		tmp->next->next = NULL;
		str = stack->rez;
		stack->rez = ft_strjoin(stack->rez, "ra\n");
		free(str);
	}
}
