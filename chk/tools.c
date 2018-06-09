/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:00:50 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/04 17:30:37 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_print_stack(t_stack *stack)
{
	t_nbr	*tmp_a;
	t_nbr	*tmp_b;
	int		i;

	stack->t ? ft_printf("\033[2J") : 0;
	stack->t ? ft_printf("\033[%d;%dH", 0, 0) : 0;
	i = stack->size_a + stack->size_b + 1;
	tmp_a = stack->a;
	tmp_b = stack->b;
	while (--i)
	{
		ft_printf("%5s%5s\n", (i - stack->size_a <= 0) ?\
			ft_itoa(tmp_a->nbr) : "", (i - stack->size_b <= 0) ?\
			ft_itoa(tmp_b->nbr) : "");
		tmp_a = (i - stack->size_a > 0) ? tmp_a : tmp_a->next;
		tmp_b = (i - stack->size_b > 0) ? tmp_b : tmp_b->next;
	}
	ft_printf("st_a--st_b\n");
	if (stack->t && stack->v)
		while (i++ < 50000000)
			;
}

int		ft_check_stack(t_stack *stack)
{
	t_nbr *tmp;
	t_nbr *a;

	tmp = stack->a;
	while (tmp)
	{
		a = tmp->next;
		while (a)
		{
			if (a->nbr == tmp->nbr)
				return (0);
			a = a->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		ft_add_nbr(t_stack *stack, int nbr)
{
	t_nbr *a;
	t_nbr *tmp;

	tmp = stack->a;
	if (!(a = (t_nbr *)malloc(sizeof(t_nbr))))
		return (0);
	a->nbr = nbr;
	a->next = NULL;
	if (!tmp)
	{
		stack->a = a;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	return (2);
}

int		ft_stack_from_str(char *str, t_stack *stack, intmax_t buf)
{
	stack->size_a = 0;
	while (*str)
	{
		buf = ft_atoi_long(str);
		stack->size_a++;
		if (_CHECK_NBR || !ft_add_nbr(stack, (int)buf))
			return (0);
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
		while (*str == ' ')
			str++;
		if (*str && (*str < '0' || *str > '9') && *str != '-')
			return (0);
	}
	return (ft_check_stack(stack) ? 1 : 0);
}

int		ft_create_stack(int ac, char **av, t_stack *stack, int j)
{
	int			i;
	intmax_t	buf;

	if (ac == 1)
		return (0);
	while (++j < ac)
	{
		i = -1;
		while (av[j][++i])
		{
			if (_CHECK && av[j][i] != '-' && av[j][i] != ' ')
				return (0);
			else if (av[j][i] == ' ' && ac == 2)
				return (ft_stack_from_str(av[1], stack, -1));
		}
	}
	j = 0;
	while (++j < ac)
	{
		buf = ft_atoi_long(av[j]);
		if (_CHECK_NBR || !ft_add_nbr(stack, (int)buf))
			return (0);
	}
	return (ft_check_stack(stack) ? 1 : 0);
}
