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

void ft_check_rez(t_stack *stack)
{
	//pa\npb\n 6
	//pb\npa\n 6
	//ra\nrra\n 7
	//rra\nra\n 7
	//rb\nrrb\n 7
	//rrb\nrb\n 7
	//ra\nrb\n -> rr\n
	//rb\nra\n -> rr\n
	//rra\nrrb\n -> rrr\n
	//rrb\nrra\n -> rrr\n
	;
}

int		main(int ac, char **av)
{
	t_stack		stack;

   stack.a = NULL;
   stack.b = NULL;
   stack.rez = NULL;
	stack.size_a = ac - 1;
   stack.size_b = 0;
	if (!ft_create_stack(ac, av, &stack, 0))
		return (write(1, "Error\n", 6));
	ft_sort_hard(&stack);
	ft_check_rez(&stack);
write(1, stack.rez, ft_strlen(stack.rez));
	return (0);
}
