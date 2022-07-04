/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:28 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 15:37:19 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_pa(t_pile *pile, int bol)
{
	if (bol)
	{
		reverserotate_b(pile);
		reverserotate_b(pile);
		push_a(pile);
		push_a(pile);
	}
	else
	{
		reverserotate_b(pile);
		push_a(pile);
	}
}

void	sort_b_normal(int *array, t_pile *pile, int left, int right)
{
	int	m;
	int	i;

	if (left + 1 == right)
		check_2_firstelem_b(pile, 1);
	else if (left < right)
	{
		i = left - 1;
		m = (right + left - 1) / 2;
		while (++i <= right)
			partition(array, pile, m);
		if (size_pile(*(pile->b)) == m + 1 - left)
		{
			sort_a_normal(array, pile, m + 1, right);
			sort_b_normal(array, pile, left, m);
		}
		else
		{
			sort_a_normal(array, pile, m + 1, right);
			sort_b_reverse(array, pile, left, m);
		}
	}
	else
		push_a(pile);
}

void	sort_b_reverse(int *array, t_pile *pile, int left, int right)
{
	int	m;
	int	i;

	if (left + 1 == right)
		check_2_firstelem_b(pile, 0);
	else if (left < right)
	{
		i = left - 1;
		m = (right + left - 1) / 2;
		while (++i <= right)
		{
			reverserotate_b(pile);
			if (top_b(pile) > array[m])
				push_a(pile);
		}
		sort_a_normal(array, pile, m + 1, right);
		sort_b_normal(array, pile, left, m);
	}
	else
		rrb_pa(pile, 0);
}

void	sort_a_normal(int *array, t_pile *pile, int left, int right)
{
	int	m;
	int	i;

	if (right == left + 1)
		check_2_firstelem_a(pile, 1);
	else if (left < right)
	{
		i = left - 1;
		m = (right + left - 1) / 2;
		while (++i <= right)
		{
			if (top_a(pile) <= array[m])
				push_b(pile);
			else
				rotate_a(pile);
		}
		if (size_pile(*(pile->a)) != right - m)
			sort_a_reverse(array, pile, m + 1, right);
		else
			sort_a_normal(array, pile, m + 1, right);
		sort_b_normal(array, pile, left, m);
	}
}

void	sort_a_reverse(int *array, t_pile *pile, int left, int right)
{
	int	m;
	int	i;

	if (right == left + 1)
		check_2_firstelem_a(pile, 0);
	else if (left < right)
	{
		i = left - 1;
		m = (right + left - 1) / 2;
		while (++i <= right)
		{
			reverserotate_a(pile);
			if (top_a(pile) <= array[m])
				push_b(pile);
		}
		sort_a_normal(array, pile, m + 1, right);
		sort_b_normal(array, pile, left, m);
	}
	else
		reverserotate_a(pile);
}
