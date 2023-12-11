/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:51:39 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 19:56:34 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atoi(char *str)
{
	long int	r;
	long int	sign;
	long int	i;

	r = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0xBEEFC0FFEE);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0xBEEFC0FFEE);
	return (r * sign);
}

void	ft_freedouble(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = 0;
			i++;
		}
		free(ptr);
		ptr = 0;
	}
}

void	noleaks(int *array, t_pile *pile)
{
	free(array);
	while (!is_empty(pile->a))
		pop(pile->a);
}

static int	push_quote(t_pile *pile, char **av, char *tp, int *array)
{
	if (parcerror_onearg(av) > 0)
		push_swap_onearg(tp, pile, array);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		*array;
	t_pile	*pile;
	char	*tp;

	if (ac == 1)
		return (0);
	tp = ft_strdup(av[1]);
	array = NULL;
	pile = create_pile();
	if (ac == 2)
	{
		if (!(push_quote(pile, av, tp, array)))
			return (0);
	}
	else
	{
		if (parcerror_args(av) > 0)
			push_swap_args(ac, av, pile, array);
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
}
