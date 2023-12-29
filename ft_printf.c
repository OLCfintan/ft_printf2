/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:13:37 by oel-mouk          #+#    #+#             */
/*   Updated: 2023/12/29 17:43:43 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char x, va_list args)
{
	int		temp;
	char	c;

	temp = 0;
	if (x == 's' || x == 'c')
	{
		if (x != 'c')
			temp = ft_putstr(va_arg(args, char *), 's');
		else
		{
			c = va_arg(args, int);
			temp = ft_putstr(&c, 'c');
		}
	}
	else if (x == 'd' || x == 'i')
		temp = ft_putnbr(va_arg(args, int));
	else if (x == 'u')
		temp = ft_putnbr(va_arg(args, unsigned int));
	else if (x == 'x' || x == 'X' || x == 'p')
		temp = ft_puthexa(va_arg(args, void *), x);
	else
		temp = ft_putstr(&x, 'c');
	return (temp);
}

int	ft_printf(char *str, ...)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (!str)
		return (-1);
	va_list(args);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			temp += ft_check(str[i++], args);
		}
		else
			temp += ft_putstr(&str[i++], 'c');
	}
	va_end(args);
	return (temp);
}
