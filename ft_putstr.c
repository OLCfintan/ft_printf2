/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:13:47 by oel-mouk          #+#    #+#             */
/*   Updated: 2023/12/29 17:13:47 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, char x)
{
	int	i;

	i = 0;
	if (x != 'c')
	{
		if (str == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
	write(1, &str[i], 1);
	return (1);
}
