/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:14:53 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/02 23:14:55 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		ft_check_sort(t_stack *stack)
{
	t_nbr	*beg;

	beg = stack->a;
	if (stack->p)
		ft_print_stack(stack);
	while (beg->next)
	{
		if (beg->nbr > beg->next->nbr)
		{
			if (stack->c)
				return (write(1, "\e[38;5;196mKO\n", 14));
			else
				return (write(1, "KO\n", 3));
		}
		beg = beg->next;
	}
	if (stack->b)
	{
		if (stack->c)
			return (write(1, "\e[38;5;196mKO\n", 14));
		else
			return (write(1, "KO\n", 3));
	}
	return (stack->c ? write(1, "\e[38;5;46mOK\n", 13) : write(1, "OK\n", 3));
}

t_func	get_fun1(char *str)
{
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'r' && str[2] &&\
		str[2] == 'a' && !str[3])
		return (&ft_rra);
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'r' && str[2] &&\
		str[2] == 'b' && !str[3])
		return (&ft_rrb);
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'r' && str[2] &&\
		str[2] == 'r' && !str[3])
		return (&ft_rrr);
	return (&ft_error);
}

t_func	get_fun(char *str)
{
	if (str[0] && str[0] == 'p' && str[1] && str[1] == 'a' && !str[2])
		return (&ft_pa);
	if (str[0] && str[0] == 'p' && str[1] && str[1] == 'b' && !str[2])
		return (&ft_pb);
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'a' && !str[2])
		return (&ft_ra);
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'b' && !str[2])
		return (&ft_rb);
	if (str[0] && str[0] == 'r' && str[1] && str[1] == 'r' && !str[2])
		return (&ft_rr);
	if (str[0] && str[0] == 's' && str[1] && str[1] == 'a' && !str[2])
		return (&ft_sa);
	if (str[0] && str[0] == 's' && str[1] && str[1] == 'b' && !str[2])
		return (&ft_sb);
	if (str[0] && str[0] == 's' && str[1] && str[1] == 's' && !str[2])
		return (&ft_ss);
	return (get_fun1(str));
}

void	ft_stk(t_stack *stack, int ac, char **av)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->v = 0;
	stack->c = 0;
	stack->f = 0;
	stack->p = 0;
	stack->t = 0;
	stack->fd = 0;
	if (ac > 2)
	{
		stack->v = ft_strchr(av[1], 'v') ? 1 : 0;
		stack->c = ft_strchr(av[1], 'c') ? 1 : 0;
		stack->f = ft_strchr(av[1], 'f') ? 1 : 0;
		stack->p = ft_strchr(av[1], 'p') ? 1 : 0;
		stack->t = ft_strchr(av[1], 't') ? 1 : 0;
	}
	stack->v = stack->t ? 1 : stack->v;
	if (stack->f)
		stack->fd = open(av[2], O_RDONLY | O_CREAT);
}

int		main(int ac, char **av)
{
	char	*str;
	t_stack	stack;
	t_func	fun;

	if (ac < 2)
		return (0);
	ft_stk(&stack, ac, av);
	if (stack.v || stack.c || stack.f || stack.p || stack.t)
	{
		ac -= stack.f ? 2 : 1;
		av += stack.f ? 2 : 1;
	}
	stack.size_a = ac - 1;
	if (!ft_create_stack(ac, av, &stack, 0))
		return (stack.c ? ERR : write(1, "Error\n", 6));
	while (get_next_line(stack.fd, (char **)&str))
	{
		fun = get_fun((char *)&str[0]);
		fun(&stack);
		free(str);
		if (fun == ft_error)
			break ;
	}
	return (fun != ft_error ? ft_check_sort(&stack) : 0);
}
