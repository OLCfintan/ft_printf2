/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:14:09 by oel-mouk          #+#    #+#             */
/*   Updated: 2023/12/29 17:46:11 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_num(long long int x, int nb)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		i++;
		x /= nb;
	}
	return (i);
}

int	ft_puthexa(void *z, char l)
{
	unsigned long int y = (unsigned long int)z;
	long int	temp;
	char		*tab;
	int			i;

	temp = 0;
	if (l == 'p')
		temp += ft_putstr("0x", 's');
	i = ft_num(y, 16);
	tab = (char *)malloc(i + 1);
	tab[i] = '\0';
	while (0 < i)
	{
		temp = y / 16;
		if (y - (temp * 16) >= 10)
			tab[--i] = (y - (temp * 16)) + 55 + 32 * (l != 'X');
		else
			tab[--i] = (y - (temp * 16)) + 48;
		y /= 16;
	}
	temp += ft_putstr(tab, 's');
	free(tab);
	return (temp + 2 * (l == 'p'));
}
