/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:15:00 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/20 18:25:29 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

static int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	printnbr(int n)
{
	if (n == -2147483648)
		return (printstr("-2147483648"));
	else if (n < 0)
		return (printchar('-') + printnbr(-n));
	else if (n > 9)
		return (printnbr(n / 10) + printnbr(n % 10));
	else
		return (printchar(n + '0'));
}

static int	checkformat(va_list param, char c)
{
	int	nbchars;

	nbchars = 0;
	if (c == 'c')
		nbchars += printchar(va_arg(param, int));
	else if (c == 's')
		nbchars += printstr(va_arg(param, char *));
	else if (c == 'd' || c == 'i')
		nbchars += printnbr(va_arg(param, int));
	return (nbchars);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		nbchars;
	int		i;

	i = 0;
	va_start(param, str);
	nbchars = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbchars += checkformat(param, str[i + 1]);
			i++;
		}
		else
			nbchars += printchar(str[i]);
		i++;
	}
	va_end(param);
	return (nbchars);
}
