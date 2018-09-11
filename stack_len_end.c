/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:51:11 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 13:51:16 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		stacklen(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nx;
		i++;
	}
	return (i);
}

t_stack	*getend(t_stack **stack)
{
	t_stack *end;

	if (!(*stack))
		return (NULL);
	end = *stack;
	while (end->nx)
		end = end->nx;
	return (end);
}
