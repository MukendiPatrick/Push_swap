/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordercheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:47:16 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/05 17:53:07 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		isrevordered(t_stack *stacka, t_stack *stackb)
{
	int tmp;

	if (stacka)
		return (0);
	else if (!(stackb))
		return (0);
	tmp = stackb->v;
	while (stackb->nx)
	{
		if ((stackb->nx)->v < tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (2);
		else
			return (0);
		stackb = stackb->nx;
	}
	return (1);
}

int		revordered(t_stack *stackb)
{
	int tmp;

	if (!(stackb))
		return (0);
	tmp = stackb->v;
	while (stackb->nx)
	{
		if ((stackb->nx)->v < tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (2);
		else
			return (0);
		stackb = stackb->nx;
	}
	return (1);
}

int		ordered(t_stack *stackb)
{
	int tmp;

	if (!(stackb))
		return (0);
	tmp = stackb->v;
	while (stackb->nx)
	{
		if ((stackb->nx)->v > tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (2);
		else
			return (0);
		stackb = stackb->nx;
	}
	return (1);
}

int		almostordered(t_stack *stackb)
{
	int tmp;
	int tmp2;

	if (!(stackb))
		return (1);
	if (ordered(stackb))
		return (1);
	tmp = stackb->v;
	tmp2 = stackb->v;
	if (almostordered_2(stackb, tmp, tmp2))
		return (1);
	else
		return (0);
	return (0);
}

int		almostordered_2(t_stack *stackb, int tmp, int tmp2)
{
	int flag;

	flag = 0;
	while (stackb)
	{
		if (!(stackb->nx))
			break ;
		if ((stackb->nx)->v > tmp)
			tmp = (stackb->nx)->v;
		else if ((stackb->nx)->v == tmp)
			return (1);
		else if (flag == 0)
			flag++;
		else
			return (0);
		stackb = stackb->nx;
	}
	if (flag == 1 && stackb->v < tmp2)
		return (1);
	return (0);
}
