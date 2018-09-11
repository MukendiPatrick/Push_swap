/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepoprot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:47:40 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 13:47:47 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static void	ppr4(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbf;
	if (b > 0 & a > 0)
	{
		udtertstck(ret, RRA, sa, sb);
		udtertstck(ret, RB, sa, sb);
	}
	else if (b > 0)
		udtertstck(ret, RB, sa, sb);
	else if (a > 0)
		udtertstck(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbf -= 1;
}

static void	ppr3(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbr;
	if (b > 0 & a > 0)
	{
		udtertstck(ret, RA, sa, sb);
		udtertstck(ret, RRB, sa, sb);
	}
	else if (b > 0)
		udtertstck(ret, RRB, sa, sb);
	else if (a > 0)
		udtertstck(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbr -= 1;
}

static void	ppr2(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbr;
	if (b > 0 & a > 0)
		udtertstck(ret, RRR, sa, sb);
	else if (b > 0)
		udtertstck(ret, RRB, sa, sb);
	else if (a > 0)
		udtertstck(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbr -= 1;
}

static void	ppr1(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbf;
	if (b > 0 & a > 0)
		udtertstck(ret, RR, sa, sb);
	else if (b > 0)
		udtertstck(ret, RB, sa, sb);
	else if (a > 0)
		udtertstck(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbf -= 1;
}

void		pprot(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int moves;

	moves = target->moves;
	while (moves)
	{
		if (target->dir == 1)
			ppr1(target, sa, sb, ret);
		else if (target->dir == 2)
			ppr2(target, sa, sb, ret);
		else if (target->dir == 3)
			ppr3(target, sa, sb, ret);
		else if (target->dir == 4)
			ppr4(target, sa, sb, ret);
		if (ordered(*sa))
			return ;
		moves--;
	}
}
