/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:14:40 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/02 14:14:41 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		main(int ac, char **av)
{
	t_stack		stack;

   stack.a = NULL;
   stack.b = NULL;
	stack.size_a = ac - 1;
   stack.size_b = 0;
	if (!ft_create_stack(ac, av, &stack, 0))
		return (write(1, "Error\n", 6));
	ft_sort_hard(&stack);
	return (0);
}
