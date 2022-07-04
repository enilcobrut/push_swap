/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:08:24 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/20 14:15:30 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_b(t_pile *pile)
{
	t_list	*tp;

	tp = *(pile->b);
	return (tp->value);
}

void	reverserotate_a(t_pile *pile)
{
	t_list	*tp;

	if (is_empty(pile->a))
		return ;
	tp = *(pile->a);
	*(pile->a) = tp->previous;
	reverserotate_save_a(pile->cmd);
}

void	reverserotate_b(t_pile *pile)
{
	t_list	*tp;

	if (is_empty(pile->b))
		return ;
	tp = *(pile->b);
	*(pile->b) = tp->previous;
	reverserotate_save_b(pile->cmd);
}

void	rotate_b(t_pile *pile)
{
	t_list	*tp;

	if (is_empty(pile->b))
		return ;
	tp = *(pile->b);
	*(pile->b) = tp->next;
	rotate_save_b(pile->cmd);
}

void	rotate_a(t_pile *pile)
{
	t_list	*tp;

	if (is_empty(pile->a))
		return ;
	tp = *(pile->a);
	*(pile->a) = tp->next;
	rotate_save_a(pile->cmd);
}
