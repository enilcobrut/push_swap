/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:08:52 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/20 14:08:53 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_pile *pile)
{
	int	value1;
	int	value2;

	if (is_empty(pile->a))
		return ;
	value1 = pop(pile->a);
	if (is_empty(pile->a))
	{
		push(pile->a, value1);
		return ;
	}
	value2 = pop(pile->a);
	push(pile->a, value1);
	push(pile->a, value2);
	save("sa\n", pile->cmd);
}

void	swap_b(t_pile *pile)
{
	int	value1;
	int	value2;

	if (is_empty(pile->b))
		return ;
	value1 = pop(pile->b);
	if (is_empty(pile->b))
	{
		push(pile->b, value1);
		return ;
	}
	value2 = pop(pile->b);
	push(pile->b, value1);
	push(pile->b, value2);
	save("sb\n", pile->cmd);
}

void	push_b(t_pile *pile)
{
	int	value;

	if (is_empty(pile->a))
		return ;
	value = pop(pile->a);
	push(pile->b, value);
	save("pb\n", pile->cmd);
}

void	push_a(t_pile *pile)
{
	int	value;

	if (is_empty(pile->b))
		return ;
	value = pop(pile->b);
	push(pile->a, value);
	save("pa\n", pile->cmd);
}

int	min_pile(t_list *top)
{
	t_list	*tp;
	int		min;
	int		result;
	int		pos;

	result = 1;
	pos = 1;
	if (is_empty(&top))
		return (0);
	tp = top;
	min = tp->value;
	while (tp->next != top)
	{
		tp = tp->next;
		pos++;
		if (tp->value < min)
		{
			min = tp->value;
			result = pos;
		}
	}
	return (result);
}
