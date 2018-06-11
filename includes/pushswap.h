/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:16:10 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/02 14:16:11 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <../libft/libft.h>
# define BUFF_SIZE 1
# define _CHECK_NBR buf > 2147483647 || buf < -2147483648
# define _CHECK (av[j][i] < '0' || av[j][i] > '9')
# define _CHECK1 (av[j][i] < '0' || av[j][i] > '9') && av[j][i] != '-'
# define _CHECK2 av[j][i] != '-' && av[j][i] != ' '
# define ERR write(1, "\e[38;5;196mError\n", 17)
# define _S_A stack->size_a
# define _S_B stack->size_b
# define _1_A stack->a->nbr
# define _1_B stack->b->nbr
# define _2_A stack->a->next->nbr
# define _2_B stack->b->next->nbr

typedef struct		s_nbr
{
	int				nbr;
	struct s_nbr	*next;
}					t_nbr;

typedef struct		s_stack
{
	int				v : 1;
	int				c : 1;
	int				f : 1;
	int				p : 1;
	int				t : 1;
	int				fd;
	t_nbr			*a;
	t_nbr			*b;
	int				size_a;
	int				size_b;
	char			*rez;
}					t_stack;

typedef void		(*t_func)(t_stack *);
int					main(int ac, char **av);
void				ft_sa(t_stack *stack);
void				ft_sb(t_stack *stack);
void				ft_ss(t_stack *stack);
void				ft_pa(t_stack *stack);
void				ft_pb(t_stack *stack);
void				ft_ra(t_stack *stack);
void				ft_rb(t_stack *stack);
void				ft_rr(t_stack *stack);
void				ft_rra(t_stack *stack);
void				ft_rrb(t_stack *stack);
void				ft_rrr(t_stack *stack);
int					ft_check_stack(t_stack *stack);
int					ft_add_nbr(t_stack *stack, int nbr);
int					ft_stack_from_str(char *str, t_stack *stack, intmax_t buf);
void				ft_sort_eazy(t_stack *stack);
int					ft_create_stack(int ac, char **av, t_stack *stack, int j);
int					get_next_line(int const fd, char **line);
void				ft_sort_buble(t_stack *stack);
void				ft_error(t_stack *stack);
void				ft_sort_hard(t_stack *stack);
int					is_sort(t_nbr *a);
int					check_median(t_stack *stack, int med, int nb, int sens);
void				qsort_b_med(t_stack *stack, int nb);
void				ft_qsort_b(t_stack *stack, int nb);
int					check_med(t_nbr *nb, int nbelem, int i, int j);
void				qsort_a_med(t_stack *stack, int nb);
void				ft_qsort_a(t_stack *stack, int nb);
int					get_nb(int j, t_nbr *nb);
void				ft_print_stack(t_stack *stack);

#endif
