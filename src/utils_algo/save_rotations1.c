/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rotations1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:48:51 by cjunker           #+#    #+#             */
/*   Updated: 2022/06/28 08:07:08 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	print_double_rotations(t_cmd *cmd)
{
	while (cmd->rotations_a > 0 && cmd->rotations_b > 0)
	{
		ft_printf("rr\n");
		cmd->rotations_a--;
		cmd->rotations_b--;
	}
	while (cmd->rotations_a < 0 && cmd->rotations_b < 0)
	{
		ft_printf("rrr\n");
		cmd->rotations_a++;
		cmd->rotations_b++;
	}
}

static void	print_rotations_a(t_cmd *cmd)
{
	while (cmd->rotations_a > 0)
	{
		ft_printf("ra\n");
		cmd->rotations_a--;
	}
	while (cmd->rotations_a < 0)
	{
		ft_printf("rra\n");
		cmd->rotations_a++;
	}
}

static void	print_rotations_b(t_cmd *cmd)
{
	while (cmd->rotations_b > 0)
	{
		ft_printf("rb\n");
		cmd->rotations_b--;
	}
	while (cmd->rotations_b < 0)
	{
		ft_printf("rrb\n");
		cmd->rotations_b++;
	}
}

void	save(char *str, t_cmd *cmd)
{
	print_double_rotations(cmd);
	print_rotations_a(cmd);
	print_rotations_b(cmd);
	ft_printf("%s", str);
}
