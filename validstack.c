/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:09:40 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/07 12:09:50 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int					validnumbers(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (ps_big_atoi(av[i]) > INT_MAX || ps_big_atoi(av[i]) < INT_MIN)
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				;
			else if (!ft_isdigit(av[i][j]))
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void			varparse(t_stack **stack, char *avin)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(avin, ' ');
	while (tmp[j])
	{
		(*stack)->v = (int)ps_big_atoi(tmp[j]);
		if (!tmp[j + 1])
			break ;
		(*stack)->nx = stackinit();
		((*stack)->nx)->pv = (*stack);
		(*stack) = (*stack)->nx;
		j++;
	}
	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

t_stack				*makestack(char **av)
{
	int		i;
	t_stack *stack;
	t_stack *begin;

	i = 1;
	stack = stackinit();
	begin = stack;
	while (av[i])
	{
		varparse(&stack, av[i]);
		if (!av[i + 1])
			return (begin);
		stack->nx = stackinit();
		(stack->nx)->pv = stack;
		stack = stack->nx;
		i++;
	}
	free(stack);
	return (begin);
}

static int			hasdupes(t_stack *stacka)
{
	int		num;
	int		flag;
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	while (stacka)
	{
		num = stacka->v;
		flag = 0;
		tmpb = tmpa;
		while (tmpb)
		{
			if (tmpb->v == num)
				flag++;
			if (flag > 1)
				return (1);
			tmpb = tmpb->nx;
		}
		stacka = stacka->nx;
	}
	return (0);
}

t_stack				*validstack(int ac, char **av, t_stack *stacka)
{
	char	**tmp;

	tmp = av;
	if (ac < 2)
		return (NULL);
	if (!(ft_strcmp("-v", tmp[1])))
		tmp++;
	if (!validnumbers(tmp))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stacka = makestack(tmp);
	if (hasdupes(stacka))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stacka);
}
