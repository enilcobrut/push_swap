/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                      :+:      :+:    :+:  	  */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:20:12 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/29 15:21:08 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(char **str, int bol1)
{
	int	i;
	int	bol;

	bol = 0;
	if (bol1)
		i = 0;
	else
		i = 1;
	while (str[i] && str[i + 1])
	{
		if (ft_atoi(str[i + 1]) < ft_atoi(str[i]))
			bol = 1;
		i++;
	}
	return (bol);
}

int	parcerror_onearg(char **av)
{
	char	**args;
	int		i;
	int		j;

	i = -1;
	args = ft_split(av[1], ' ');
	while (args[++i])
	{
		if (ft_atoi(args[i]) == 0xBEEFC0FFEE
			|| ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
		{
			ft_freedouble(args);
			return (0);
		}
		j = i + 1;
		if (!check_double(i, j, args))
			return (0);
	}
	if (is_sorted(args, 1) == 0)
		exit(0);
	ft_freedouble(args);
	return (1);
}

int	parcerror_args(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0xBEEFC0FFEE
			|| ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (0);
			j++;
		}
		i++;
	}
	if (is_sorted(av, 0) == 0)
		exit(0);
	return (1);
}

void	push_swap_args(int ac, char **av, t_pile *pile, int *array)
{
	int		i;
	int		j;

	j = 1;
	i = 0;
	array = malloc(sizeof(int) * (ac - 1));
	while (j < ac)
		array[i++] = ft_atoi(av[j++]);
	j = ac - 2;
	i = 0;
	while (j >= 0)
		push(pile->a, array[j--]);
	if (size_pile(*(pile->a)) == 3 || size_pile(*(pile->a)) == 5)
		little_algo(pile);
	else
	{
		sortarray(array, ac - 1);
		sort_a_normal(array, pile, 0, ac - 2);
	}
	noleaks(array, pile);
}

void	push_swap_onearg(char *tp, t_pile *pile, int *array)
{
	int		i;
	int		j;
	int		args_len;
	char	**args;

	args_len = countwords(tp, ' ');
	args = ft_split(tp, ' ');
	j = 0;
	i = 0;
	array = malloc(sizeof(int) * (args_len));
	while (j < args_len)
		array[i++] = ft_atoi(args[j++]);
	ft_freedouble(args);
	j = args_len - 1;
	i = 0;
	while (j >= 0)
		push(pile->a, array[j--]);
	if (size_pile(*(pile->a)) == 3 || size_pile(*(pile->a)) == 5)
		little_algo(pile);
	else
	{
		sortarray(array, args_len);
		sort_a_normal(array, pile, 0, args_len - 1);
	}
	noleaks(array, pile);
}
