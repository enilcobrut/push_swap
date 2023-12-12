/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:36:52 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 18:31:36 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	normal_push_min(t_pile *pile, int pos_min)
{
	int	i;

	i = 1;
	while (i < pos_min)
	{
		rotate_a(pile);
		i++;
	}
}

static void	reverse_push_min(t_pile *pile, int pos_min, int size)
{
	int	i;

	i = size;
	while (i >= pos_min)
	{
		reverserotate_a(pile);
		i--;
	}
}

static void	push_min(t_pile *pile)
{
	int	pos_min;
	int	size;
	int	m;

	pos_min = min_pile(*(pile->a));
	size = size_pile(*(pile->a));
	m = size / 2;
	if (pos_min > m + 1)
		reverse_push_min(pile, pos_min, size);
	if (pos_min <= m + 1)
		normal_push_min(pile, pos_min);
	push_b(pile);
}

static void	only_5(t_pile *pile)
{
	push_min(pile);
	push_min(pile);
	only_3(pile);
	push_a(pile);
	push_a(pile);
}

void	little_algo(t_pile *pile)
{
	if (size_pile(*(pile->a)) == 3)
	{
		only_3(pile);
		return ;
	}
	if (size_pile(*(pile->a)) == 5)
	{
		only_5(pile);
		return ;
	}
}
