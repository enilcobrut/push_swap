/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:17:48 by cjunker           #+#    #+#             */
/*   Updated: 2022/07/04 19:57:55 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*previous;
	struct s_list	*next;
	int				value;
}	t_list;

typedef struct s_cmd
{
	int	rotations_a;
	int	rotations_b;
}	t_cmd;

typedef struct s_pile
{
	t_list	**a;
	t_list	**b;
	t_cmd	*cmd;
}	t_pile;

void		sort_a_normal(int *array, t_pile *pile, int left, int right);
void		sort_a_reverse(int *array, t_pile *pile, int left, int right);
void		sort_b_normal(int *array, t_pile *pile, int left, int right);
void		sort_b_reverse(int *array, t_pile *pile, int left, int right);
int			is_empty(t_list **a);
void		push(t_list **a, int value);
int			pop(t_list **a);
void		print(t_list **a);
int			top_b(t_pile *pile);
int			top2_b(t_pile *pile);
int			top3_b(t_pile *pile);
int			top_a(t_pile *pile);
int			top2_a(t_pile *pile);
int			top3_a(t_pile *pile);
void		reverserotate_a(t_pile *pile);
void		reverserotate_b(t_pile *pile);
void		rotate_a(t_pile *pile);
void		rotate_b(t_pile *pile);
void		swap_a(t_pile *pile);
void		swap_b(t_pile *pile);
void		push_a(t_pile *pile);
void		push_b(t_pile *pile);
void		check_2_firstelem_a(t_pile *pile, int bol);
void		check_2_firstelem_b(t_pile *pile, int bol);
void		sortarray(int *tab, int size);
t_pile		*create_pile(void);
int			ft_printf(const char *str, ...);
int			size_pile(t_list *top);
void		partition(int *array, t_pile *pile, int m);
void		rotate_save_a(t_cmd *cmd);
void		rotate_save_b(t_cmd *cmd);
void		reverserotate_save_a(t_cmd *cmd);
void		reverserotate_save_b(t_cmd *cmd);
void		save(char *str, t_cmd *cmd);
void		only_3(t_pile *pile);
char		**ft_split(char const *s, char c);
int			countwords(char const *s, char c);
void		push_swap_onearg(char *tp, t_pile *pile, int *array);
void		push_swap_args(int ac, char **av, t_pile *pile, int *array);
int			parcerror_args(char **av);
int			parcerror_onearg(char **av);
char		*ft_strdup(const char *s1);
long int	ft_atoi(char *str);
void		ft_freedouble(char **ptr);
size_t		ft_strlen(char const *str);
void		noleaks(int *array, t_pile *pile);
void		reverserotate_a1(t_pile *pile);
void		little_algo(t_pile *pile);
int			min_pile(t_list *top);
void		rrb_pa(t_pile *pile, int bol);
int			check_double(int i, int j, char **args);

#endif