/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:25:12 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/30 14:19:46 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list **a)
{
	if (*a == NULL)
		return (1);
	else
		return (0);
}

void	push(t_list **a, int value)
{
	t_list	*tp;
	t_list	*newtop;

	newtop = malloc(sizeof(t_list));
	newtop->value = value;
	if (is_empty(a))
	{
		newtop->next = newtop;
		newtop->previous = newtop;
	}
	else
	{
		tp = *a;
		newtop->next = tp;
		newtop->previous = tp->previous;
		tp->previous->next = newtop;
		tp->previous = newtop;
	}
	*a = newtop;
}

int	pop(t_list **a)
{
	t_list	*tp;
	int		result;

	tp = *a;
	result = tp->value;
	if (tp->next != tp)
	{
		*a = tp->next;
		tp->next->previous = tp->previous;
		tp->previous->next = tp->next;
	}
	else
		*a = NULL;
	free(tp);
	return (result);
}

int	size_pile(t_list *top)
{
	t_list	*tp;
	int		i;

	if (is_empty(&top))
		return (0);
	i = 1;
	tp = top;
	while (tp->next != top)
	{
		tp = tp->next;
		i++;
	}
	return (i);
}

t_pile	*create_pile(void)
{
	t_pile	*result;

	result = malloc(sizeof(t_pile));
	result->a = malloc(sizeof(t_list *));
	result->b = malloc(sizeof(t_list *));
	*(result->a) = NULL;
	*(result->b) = NULL;
	result->cmd = malloc(sizeof(t_cmd));
	result->cmd->rotations_a = 0;
	result->cmd->rotations_b = 0;
	return (result);
}
