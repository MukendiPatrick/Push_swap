/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:45:45 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 13:45:51 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	doop(t_onum num, t_stack **sa, t_stack **sb)
{
	if (num == SA)
		fsa(sa, sb);
	else if (num == SB)
		fsb(sa, sb);
	else if (num == SS)
		fss(sa, sb);
	else if (num == PA)
		fpa(sa, sb);
	else if (num == PB)
		fpb(sa, sb);
	else if (num == RA)
		fra(sa, sb);
	else if (num == RB)
		frb(sa, sb);
	else if (num == RR)
		frr(sa, sb);
	else if (num == RRA)
		frra(sa, sb);
	else if (num == RRB)
		frrb(sa, sb);
	else if (num == RRR)
		frrr(sa, sb);
}

void	dooprev(t_onum num, t_stack **sa, t_stack **sb)
{
	if (num == SA)
		fsb(sa, sb);
	else if (num == SB)
		fsa(sa, sb);
	else if (num == SS)
		fss(sa, sb);
	else if (num == PA)
		fpb(sa, sb);
	else if (num == PB)
		fpa(sa, sb);
	else if (num == RA)
		frb(sa, sb);
	else if (num == RB)
		fra(sa, sb);
	else if (num == RR)
		frr(sa, sb);
	else if (num == RRA)
		frrb(sa, sb);
	else if (num == RRB)
		frra(sa, sb);
	else if (num == RRR)
		frrr(sa, sb);
}
