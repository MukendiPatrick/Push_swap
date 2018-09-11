/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:07:54 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 14:08:00 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int r;

	r = 1;
	if (nb < 0 || nb == 0)
	{
		return (0);
	}
	while (r < 46341)
	{
		if ((r * r) == nb)
		{
			return (r);
		}
		r = (r + 1);
	}
	return (0);
}
