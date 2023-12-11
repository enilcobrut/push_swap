/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:27:25 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 15:46:50 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	check_2_firstelem_a(t_pile *pile, int bol)
{
	if (bol)
	{
		if (top_a(pile) > top2_a(pile))
			swap_a(pile);
	}
	else
	{
		reverserotate_a(pile);
		reverserotate_a(pile);
		if (top_a(pile) > top2_a(pile))
			swap_a(pile);
	}
}

void	check_2_firstelem_b(t_pile *pile, int bol)
{
	if (bol)
	{
		push_a(pile);
		push_a(pile);
		if (top_a(pile) > top2_a(pile))
			swap_a(pile);
	}
	else
	{
		rrb_pa(pile, 1);
		if (top_a(pile) > top2_a(pile))
			swap_a(pile);
	}
}

void	partition(int *array, t_pile *pile, int m)
{
	if (top_b(pile) > array[m])
		push_a(pile);
	else
		rotate_b(pile);
}

static void	sa_and_rra(t_pile *pile, int bol)
{
	if (bol)
	{
		swap_a(pile);
		reverserotate_a(pile);
	}
	else
	{
		reverserotate_a(pile);
		swap_a(pile);
	}
}

void	only_3(t_pile *pile)
{
	if (top_a(pile) > top2_a(pile) && top_a(pile) < top3_a(pile)
		&& top2_a(pile) < top3_a(pile))
		swap_a(pile);
	if (top_a(pile) < top2_a(pile) && top_a(pile) > top3_a(pile)
		&& top2_a(pile) > top3_a(pile))
		reverserotate_a(pile);
	if (top_a(pile) > top2_a(pile) && top_a(pile) > top3_a(pile)
		&& top2_a(pile) > top3_a(pile))
		sa_and_rra(pile, 1);
	if (top_a(pile) > top2_a(pile) && top_a(pile) > top3_a(pile)
		&& top2_a(pile) < top3_a(pile))
		rotate_a(pile);
	if (top_a(pile) < top2_a(pile) && top_a(pile) < top3_a(pile)
		&& top2_a(pile) > top3_a(pile))
		sa_and_rra(pile, 0);
	save("", pile->cmd);
}
