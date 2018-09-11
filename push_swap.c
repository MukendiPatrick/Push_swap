/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:36:21 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/06 16:47:47 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static void	cleanup(t_stack **sa, t_stack **sb, t_out **ret)
{
	t_stack *nx;
	t_out	*nxo;

	nxo = *ret;
	nx = *sa;
	while (nx)
	{
		nx = (*sa)->nx;
		free(*sa);
		*sa = nx;
	}
	nx = *sb;
	while (nx)
	{
		nx = (*sb)->nx;
		free(*sb);
		*sb = nx;
	}
	while (nxo)
	{
		nxo = (*ret)->nx;
		free(*ret);
		*ret = nxo;
	}
}

int			main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack *stackb;
	t_out	*ret;

	stacka = NULL;
	stackb = NULL;
	if (!(stacka = validstack(ac, av, stacka)))
		return (0);
	ret = outinit();
	sorting(&stacka, &stackb, ret);
	printret(ret);
	cleanup(&stacka, &stackb, &ret);
	return (0);
}
