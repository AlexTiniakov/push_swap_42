/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 12:42:22 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/03 12:42:23 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}

void	ft_rrb(t_stack *stack)
{
	t_nbr *tmp;
	t_nbr *tmp1;
	char *str;

	if (stack->b && stack->b->next)
	{
		tmp = stack->b;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp1 = tmp->next;
		tmp->next = NULL;
		tmp = tmp1;
		tmp->next = stack->b;
		stack->b = tmp;
		str = stack->rez;
		stack->rez = ft_strjoin(stack->rez, "rrb\n");
		free(str);
	}
}

void	ft_rra(t_stack *stack)
{
	t_nbr *tmp;
	t_nbr *tmp1;
	char *str;

	if (stack->a && stack->a->next)
	{
		tmp = stack->a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp1 = tmp->next;
		tmp->next = NULL;
		tmp = tmp1;
		tmp->next = stack->a;
		stack->a = tmp;
		str = stack->rez;
		stack->rez = ft_strjoin(stack->rez, "rra\n");
		free(str);
	}
}
