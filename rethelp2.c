/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rethelp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:37:18 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 11:37:44 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		getsmallest(t_stack *sb)
{
	int		smallest;
	t_stack	*tmp;

	tmp = sb;
	smallest = tmp->v;
	while (tmp)
	{
		if (smallest > tmp->v)
			smallest = tmp->v;
		tmp = tmp->nx;
	}
	return (smallest);
}

void	rvudrtstckrv(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *tmp;

	tmp = ret;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->num = op;
	tmp->nx = outinit();
	dooprev(op, sa, sb);
}

void	udtertstck(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *tmp;

	tmp = ret;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->num = op;
	tmp->nx = outinit();
	doop(op, sa, sb);
}

void	printret(t_out *ret)
{
	int i;

	i = 0;
	while (ret)
	{
		if (ret->num == NOTHING)
		{
			break ;
		}
		printelement2(ret->num);
		ret = ret->nx;
		i++;
	}
}

int		retnumber(t_out *ret)
{
	int i;

	i = 0;
	while (ret->num != NOTHING)
	{
		i++;
		ret = ret->nx;
	}
	return (i);
}
