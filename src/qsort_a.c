/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:23:20 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/07 17:23:21 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	qsort_a_med(t_stack *stack, int nb)
{
	int i;
	int c;
	int med;

	med = check_med(stack->a, nb, 0, 0);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stack, med, nb, 0) != 0)
	{
		if (stack->a->nbr >= med)
		{
			ft_ra(stack);
			c++;
		}
		else
			ft_pb(stack);
		i++;
	}
	while (c-- > 0 && (nb / 2 + nb % 2) != _S_A)
		ft_rra(stack);
}

void	ft_qsort_a(t_stack *stack, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && _1_A > _2_A)
			ft_sa(stack);
		return ;
	}
	qsort_a_med(stack, nb);
	ft_qsort_a(stack, nb / 2 + nb % 2);
	ft_qsort_b(stack, nb / 2);
}
