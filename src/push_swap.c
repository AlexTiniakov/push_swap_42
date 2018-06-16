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

void ft_check_rez(t_stack *stack, char *str, char *tmp, char *tab)
{
    while (ft_strstr(stack->rez, "pa\npb\n") || ft_strstr(stack->rez, "pb\npa\n")\
|| ft_strstr(stack->rez, "\nra\nrra\n") || ft_strstr(stack->rez, "rra\nra\n") ||\
ft_strstr(stack->rez, "\nrb\nrrb\n") || ft_strstr(stack->rez, "rrb\nrb\n"))
{
    if ((str = ft_strstr(stack->rez, "pa\npb\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab);
        stack->rez = ft_strjoin(tmp, str + 6);
        free(tab);
        free(tmp);
    }
    else if ((str = ft_strstr(stack->rez, "pb\npa\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab);
        stack->rez = ft_strjoin(tmp, str + 6);
        free(tab);
        free(tmp);
    }
    else if ((str = ft_strstr(stack->rez, "\nra\nrra\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab + 1);
        stack->rez = ft_strjoin(tmp, str + 8);
        free(tab);
        free(tmp);
    }
    else if ((str = ft_strstr(stack->rez, "rra\nra\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab);
        stack->rez = ft_strjoin(tmp, str + 7);
        free(tab);
        free(tmp);
    }
    else if ((str = ft_strstr(stack->rez, "\nrb\nrrb\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab + 1);
        stack->rez = ft_strjoin(tmp, str + 8);
        free(tab);
        free(tmp);
    }
    else if ((str = ft_strstr(stack->rez, "rrb\nrb\n")))
    {
        tab = stack->rez;
        tmp = ft_strncpy((char *)malloc(ft_strlen(tab)), tab, str - tab);
        stack->rez = ft_strjoin(tmp, str + 7);
        free(tab);
        free(tmp);
    }
}
}

int		main(int ac, char **av)
{
	t_stack		stack;
	t_stack     stk;

   stack.a = NULL;
   stack.b = NULL;
   stack.rez = NULL;
	stack.size_a = ac - 1;
   stack.size_b = 0;
   stk.a = NULL;
   stk.b = NULL;
   stk.rez = NULL;
    stk.size_a = ac - 1;
   stk.size_b = 0;
	if (!ft_create_stack(ac, av, &stack, 0))
		return (write(1, "Error\n", 6));
	if (!ft_create_stack(ac, av, &stk, 0))
		return (write(1, "Error\n", 6));
	ft_sort_hard(&stack);
	ft_sort_buble(&stk);
	//ft_check_rez(&stack, NULL, NULL, NULL);
	//ft_check_rez(&stk, NULL, NULL, NULL);
	ft_strlen(stack.rez) < ft_strlen(stk.rez) ? write(1, stack.rez, ft_strlen(stack.rez)) : write(1, stk.rez, ft_strlen(stk.rez));
	return (0);
}
