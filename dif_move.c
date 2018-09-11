/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dif_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:45:23 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 13:45:26 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void		rotcor(t_out *ret, t_stack **sa, t_stack **sb, int descending)
{
	int tmp;

	tmp = 0;
	if (descending)
	{
		tmp = getlargest(*sb);
		if (wheredestj(*sb, tmp) >= 0)
			while ((*sb)->v != tmp)
				udtertstck(ret, RB, sa, sb);
		else
			while ((*sb)->v != tmp)
				udtertstck(ret, RRB, sa, sb);
	}
	else
	{
		tmp = getsmallest(*sa);
		if (wheredestj(*sa, tmp) >= 0)
			while ((*sa)->v != tmp)
				udtertstck(ret, RA, sa, sb);
		else
			while ((*sa)->v != tmp)
				udtertstck(ret, RRA, sa, sb);
	}
}

void		astructmoves(t_stack *sa)
{
	int		i;
	t_stack *tmpa2;

	i = 0;
	tmpa2 = sa;
	while (sa)
	{
		sa->maf = i;
		sa = sa->nx;
		i++;
	}
	tmpa2->mar = 0;
	tmpa2 = tmpa2->nx;
	i--;
	while (tmpa2)
	{
		tmpa2->mar = i;
		tmpa2 = tmpa2->nx;
		i--;
	}
}

static void	movedirhelp(t_stack *sa, int *ar)
{
	if (ar[0] <= ar[1] && ar[0] <= ar[2] && ar[0] <= ar[3])
	{
		sa->moves = ar[0];
		sa->dir = 1;
	}
	else if (ar[1] <= ar[0] && ar[1] <= ar[2] && ar[1] <= ar[3])
	{
		sa->moves = ar[1];
		sa->dir = 2;
	}
	else if (ar[2] <= ar[0] && ar[2] <= ar[1] && ar[2] <= ar[3])
	{
		sa->moves = ar[2];
		sa->dir = 3;
	}
	else if (ar[3] <= ar[1] && ar[3] <= ar[0] && ar[3] <= ar[2])
	{
		sa->moves = ar[3];
		sa->dir = 4;
	}
}

void		movedir(t_stack *sa)
{
	int *ar;

	ar = (int *)malloc(sizeof(int) * 4);
	while (sa)
	{
		ar[0] = ((sa->maf > sa->mbf) ? sa->maf : sa->mbf);
		ar[1] = ((sa->mar > sa->mbr) ? sa->mar : sa->mbr);
		ar[2] = sa->maf + sa->mbr;
		ar[3] = sa->mar + sa->mbf;
		movedirhelp(sa, ar);
		sa = sa->nx;
	}
	free(ar);
}
