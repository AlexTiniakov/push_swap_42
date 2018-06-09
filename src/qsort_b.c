/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:23:46 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/07 17:23:48 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	qsort_b_med(t_stack *stack, int nb)
{
	int i;
	int c;
	int med;

	med = check_med(stack->b, nb, 0, 0);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stack, med, nb, 1))
	{
		if (stack->b->nbr < med)
		{
			ft_rb(stack);
			c++;
		}
		if (stack->b->nbr >= med)
			ft_pa(stack);
		i++;
	}
	while (c-- > 0 && nb / 2 != _S_B)
		ft_rrb(stack);
}

void	ft_qsort_b(t_stack *stack, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && _1_B < _2_B)
			ft_sb(stack);
		while (nb--)
			ft_pa(stack);
		return ;
	}
	qsort_b_med(stack, nb);
	ft_qsort_a(stack, nb / 2 + nb % 2);
	ft_qsort_b(stack, nb / 2);
}
