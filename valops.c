/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:41:33 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/06 17:32:50 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int			notgetop(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->fp = &fsa;
	else if (!(ft_strcmp(line, "sb")))
		list->fp = &fsb;
	else if (!(ft_strcmp(line, "ss")))
		list->fp = &fss;
	else if (!(ft_strcmp(line, "pa")))
		list->fp = &fpa;
	else if (!(ft_strcmp(line, "pb")))
		list->fp = &fpb;
	else if (!(ft_strcmp(line, "ra")))
		list->fp = &fra;
	else if (!(ft_strcmp(line, "rb")))
		list->fp = &frb;
	else if (!(ft_strcmp(line, "rr")))
		list->fp = &frr;
	else if (!(ft_strcmp(line, "rra")))
		list->fp = &frra;
	else if (!(ft_strcmp(line, "rrb")))
		list->fp = &frrb;
	else if (!(ft_strcmp(line, "rrr")))
		list->fp = &frrr;
	else
		return (1);
	return (0);
}

static int	openum(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->op = sa;
	else if (!(ft_strcmp(line, "sb")))
		list->op = sb;
	else if (!(ft_strcmp(line, "ss")))
		list->op = ss;
	else if (!(ft_strcmp(line, "pa")))
		list->op = pa;
	else if (!(ft_strcmp(line, "pb")))
		list->op = pb;
	else if (!(ft_strcmp(line, "ra")))
		list->op = ra;
	else if (!(ft_strcmp(line, "rb")))
		list->op = rb;
	else if (!(ft_strcmp(line, "rr")))
		list->op = rr;
	else if (!(ft_strcmp(line, "rra")))
		list->op = rra;
	else if (!(ft_strcmp(line, "rrb")))
		list->op = rrb;
	else if (!(ft_strcmp(line, "rrr")))
		list->op = rrr;
	else
		return (1);
	return (0);
}

t_op		*getoplist(void)
{
	char	*line;
	t_op	*list;
	t_op	*begin;
	t_op	*prev;

	line = NULL;
	list = opsinit();
	begin = list;
	prev = list;
	getoplist_1(line, list, prev);
	return (begin);
}

void		getoplist_1(char *line, t_op *list, t_op *prev)
{
	while (get_next_line(0, &line))
	{
		if (notgetop(list, line))
		{
			if (ft_strequ(line, ""))
			{
				free(line);
				break ;
			}
			write(2, "Error\n", 6);
			exit(1);
		}
		openum(list, line);
		list->next = opsinit();
		prev = list;
		list = list->next;
		free(line);
	}
	free(list);
	prev->next = NULL;
}
