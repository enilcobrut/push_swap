/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:50:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 19:57:30 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_save_a(t_cmd *cmd)
{
	cmd->rotations_a++;
}

void	rotate_save_b(t_cmd *cmd)
{
	cmd->rotations_b++;
}

void	reverserotate_save_a(t_cmd *cmd)
{
	cmd->rotations_a--;
}

void	reverserotate_save_b(t_cmd *cmd)
{
	cmd->rotations_b--;
}

int	check_double(int i, int j, char **args)
{
	while (args[j])
	{
		if (ft_atoi(args[j]) == ft_atoi(args[i]))
		{
			ft_freedouble(args);
			return (0);
		}
		j++;
	}
	return (1);
}
