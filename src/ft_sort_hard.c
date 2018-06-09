/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:59:54 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/06 12:59:56 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		check_median(t_stack *stack, int med, int nb, int sens)
{
	t_nbr	*tmp;
	int		i;

	i = 0;
	tmp = sens == 1 ? stack->b : stack->a;
	while (tmp && ++i <= nb)
	{
		if (tmp->nbr < med && sens == 0)
			return (1);
		if (tmp->nbr >= med && sens == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		get_nb(int j, t_nbr *nb)
{
	t_nbr *tmp;

	tmp = nb;
	while (--j && tmp && tmp->next)
		tmp = tmp->next;
	return (tmp->nbr);
}

int		check_med(t_nbr *nb, int nbelem, int i, int j)
{
	t_nbr	*tmp;
	t_nbr	*tab;
	int		nbb;
	int		med;

	tmp = nb;
	while (tmp && j < nbelem)
	{
		med = 0;
		i = 0;
		nbb = tmp->nbr;
		tab = nb;
		while (tab && i < nbelem)
		{
			if (nbb != tab->nbr)
				(tab->nbr > nbb) ? med++ : med--;
			tab = tab->next;
			i++;
		}
		if ((med == -1 && (nbelem) % 2 == 0) || (med == 0 && (nbelem) % 2))
			return (nbb);
		tmp = tmp->next;
		j++;
	}
	return (0);
}

void	sort_three(int a, int b, int c, t_stack *stack)
{
	if (c > a && c < b)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (a > b && a < c)
		ft_sa(stack);
	else if (a > c && a < b)
		ft_rra(stack);
	else if (c > b && c < a)
		ft_ra(stack);
	else
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}

void	ft_sort_hard(t_stack *stack)
{
	if (stack->size_a > 3 && !is_sort(stack->a))
		stack->size_a <= 6 ? ft_sort_buble(stack) : ft_qsort_a(stack, _S_A);
	else if (stack->size_a <= 3 && !is_sort(stack->a))
	{
		if (stack->size_a == 2)
			ft_sa(stack);
		else if (stack->size_a == 3)
			sort_three(stack->a->nbr, stack->a->next->nbr,\
						stack->a->next->next->nbr, stack);
	}
}
