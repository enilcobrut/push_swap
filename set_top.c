/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:19:32 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/22 15:09:03 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_a(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->a);
	return (tp->value);
}

int	top2_a(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->a);
	return (tp->next->value);
}

int	top3_a(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->a);
	return (tp->next->next->value);
}

int	top2_b(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->b);
	return (tp->next->value);
}

int	top3_b(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->b);
	return (tp->next->next->value);
}
