/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshisw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:59:33 by mtshisw           #+#    #+#             */
/*   Updated: 2018/09/04 13:59:43 by mtshisw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill_char(char *value, char *s, int len, int i)
{
	int	k;

	k = 0;
	while (i <= len)
	{
		value[k] = s[i];
		k++;
		i++;
	}
	value[k] = '\0';
}
