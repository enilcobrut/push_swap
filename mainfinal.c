#include <stdio.h>
#include <stdlib.h>
typedef struct	cell
{
	struct cell	*previous;
	struct cell	*next;
	int	value;
}	list;

typedef struct  cmd
{
        int     rotations_a;
        int     rotations_b;
}       t_cmd;

typedef struct truc
{
	list **a;
	list **b;
	int total_size;
	t_cmd	*cmd;
}	pile;

void	printseparateur();
void    Sort_a_normal(int *arra, pile *pile, int left, int right);
void    Sort_a_reverse(int *arra, pile *pile, int left, int right);
void    Sort_b_normal(int *arra, pile *pile, int left, int right);
void    Sort_b_reverse(int *arra, pile *pile, int left, int right);
void	double_swap(pile *pile, int left, int right);
int	pile_size(list *top);
void	save(char *str, t_cmd *cmd);
void	print_rotate_a(t_cmd *cmd);
void	print_rotate_b(t_cmd *cmd);
void    print_double_rotate(t_cmd *cmd);
int	isEmpty(list **a)
{
	if (*a == NULL)
		return 1;
	else
		return 0;
}
void	push(list **a, int value)
{
	list *tp;
	list *newtop;

	newtop = malloc(sizeof(list));
	newtop->value = value;
	if (isEmpty(a))
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

int	pop(list **a)
{
	list *tp;
	int	result;

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

void	print(list **a)
{
	list *current;

	if (isEmpty(a))
	{
		printf("la liste est vide rien a afficher\n");
		return;
	}
	current = *a;
	printf("%d\n", current->value);
	while(current->next != *a)
	{
		current = current->next;
		printf("%d\n", current->value);
	}
}

void	rotate(list **a)
{
	list *tp;
	
	if (isEmpty(a))
		return ;
	tp = *a;
	*a = tp->next;
}

void	reverserotate(list **a)
{
	list *tp;
	if (isEmpty(a))
		return ;
	tp = *a;
	*a = tp->previous;
}

int     top_b(pile *pile)
{       
        list *tp;
        
        tp = *(pile->b);
        return (tp->value);
}

int     top2_b(pile *pile)
{
        list *tp;

        tp = *(pile->b);
        return (tp->next->value);
}

int	top2_a(pile *pile)
{
	list	*tp;
	tp = *(pile->a);
	return (tp->next->value);
}

int     top3_a(pile *pile)
{
        list    *tp;
        tp = *(pile->a);
        return (tp->next->next->value);
}

int     top3_b(pile *pile)
{       
        list    *tp;
        tp = *(pile->b);
        return (tp->next->next->value);
}

int	top_a(pile *pile)
{
	list *tp;
	
	tp = *(pile->a);
	return (tp->value);
}

void	swap_a(pile *pile, int Bool)
{
	int value1;
	int value2;

	if (isEmpty(pile->a))
		return;
	value1 = pop(pile->a);
	if (isEmpty(pile->a))
	{
		push(pile->a, value1);
		return ;
	}
	value2 = pop(pile->a);
	push(pile->a, value1);
	push(pile->a, value2);
	if (Bool)
		save("sa\n", pile->cmd);
}

void	save(char *str, t_cmd *cmd)
{
	print_double_rotate(cmd);
	print_rotate_a(cmd);
	print_rotate_b(cmd);
	printf("%s", str);
}

void    rotate_save_a(t_cmd *cmd)
{
	cmd->rotations_a++;	
}

void    rotate_save_b(t_cmd *cmd)
{       
        cmd->rotations_b++;
}



void    reverserotate_save_a(t_cmd *cmd)
{       
        cmd->rotations_a--; 
}

void    reverserotate_save_b(t_cmd *cmd)
{       
        cmd->rotations_b--;
}


void    print_double_rotate(t_cmd *cmd)
{       
        while (cmd->rotations_a > 0 && cmd->rotations_b > 0)
        {       
                printf("rr\n");
                cmd->rotations_a--;
		cmd->rotations_b--;
        }
        while(cmd->rotations_a < 0 && cmd->rotations_b < 0)
        {       
                printf("rrr\n");
                cmd->rotations_a++;
		cmd->rotations_b++;
        }
}



void	print_rotate_a(t_cmd *cmd)
{
	while (cmd->rotations_a > 0)
	{
		printf("ra\n");
		cmd->rotations_a--;
	}
	while(cmd->rotations_a < 0)
	{
		printf("rra\n");
		cmd->rotations_a++;
	}
}


void    print_rotate_b(t_cmd *cmd)
{       
        while (cmd->rotations_b > 0)
        {
                printf("rb\n");
                cmd->rotations_b--;
        }
        while(cmd->rotations_b < 0)
        {
                printf("rrb\n");
                cmd->rotations_b++;
        }
}

void    swap_b(pile *pile, int Bool)
{
        int value1;
        int value2;

        if (isEmpty(pile->b))
                return;
        value1 = pop(pile->b);
        if (isEmpty(pile->b))
        {
                push(pile->b, value1);
                return ;
        }
        value2 = pop(pile->b);
        push(pile->b, value1);
        push(pile->b, value2);
	if (Bool)
        	save("sb\n", pile->cmd);
}

void	push_b(pile *pile)
{
	int value;

	if (isEmpty(pile->a))
		return ;
	value = pop(pile->a);
	push(pile->b, value);
	save("pb\n", pile->cmd);	
}

void	push_a(pile *pile)
{
	int value;
	if (isEmpty(pile->b))
		return ;
	value = pop(pile->b);
	push(pile->a, value);
	save("pa\n", pile->cmd);
}


void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sortarray(int *tab, int size)
{
	int pivot;
	int i;
	int j;

	if (size < 2)
		return ;
	pivot = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (tab[j] < pivot)
			ft_swap(&tab[i++], &tab[j]);
	if (tab[i] > tab[size])
		ft_swap(&tab[i], &tab[size]);
	sortarray(tab, i);
	sortarray(tab + i + 1, size - i);
}

int     pile_size(list *top)
{
        list    *tp;
        int     i;

        i = 1;
        tp = top;
        if (isEmpty(&top))
                return (0);
        while (tp->next != top)
        {
                tp = tp->next;
                i++;
        }
        return (i);
}

void    Sort_b_normal(int *array, pile *pile, int left, int right)
{

        int     m;
        int     i;
	
	if (left + 1 == right)
	{
		push_a(pile);
		push_a(pile);
		if (top_a(pile) > top2_a(pile))
			swap_a(pile, 1);
	}
        else if (left < right)
        {
                i = left;
                m = (right + left - 1) / 2;
                while (i <= right)
                {
                        if (top_b(pile) > array[m])
                        	push_a(pile);
                        else
                        {
                        	rotate(pile->b);
				rotate_save_b(pile->cmd);
                        }
                        i++;
                }
		if (pile_size(*(pile->b)) == m + 1 - left)
		{
	//		double_swap(pile, left, right);
			Sort_a_normal(array, pile, m + 1, right);
			Sort_b_normal(array, pile, left, m);
		}
		else
		{
                	Sort_a_normal(array, pile, m + 1, right);
			Sort_b_reverse(array, pile, left, m);
		}
        }
	else
		push_a(pile);
}

void    Sort_b_reverse(int *array, pile *pile, int left, int right)
{

        int     m;
        int     i;
	
	if (left + 1 == right)
	{
		reverserotate(pile->b);
		reverserotate(pile->b);
		reverserotate_save_b(pile->cmd);
		reverserotate_save_b(pile->cmd);
		push_a(pile);
		push_a(pile);
		if (top_a(pile) > top2_a(pile))
			swap_a(pile, 1);
	}
        else if (left < right)
        {
                i = left;
                m = (right + left - 1) / 2;
                while (i <= right)
                {
                        reverserotate(pile->b);
			reverserotate_save_b(pile->cmd);
                        if (top_b(pile) > array[m])
                                push_a(pile);
                        i++;
                }
	//	double_swap(pile, left, right);
                Sort_a_normal(array, pile, m + 1, right);
                Sort_b_normal(array, pile, left, m);
        }
        else
        {
                reverserotate(pile->b);
		reverserotate_save_b(pile->cmd);
		push_a(pile);
        }

}

void    swap_a_and_b(pile *pile)
{
        swap_a(pile, 0);
        swap_b(pile, 0);
        save("ss\n", pile->cmd);
}


void    double_swap(pile *pile, int left, int right)
{
	if (left + 4 >= right && left + 3 <= right && top_a(pile) > top2_a(pile) && top_b(pile) < top2_b(pile))
        {      
  
		if (left + 4 <= right && top2_a(pile) < top3_a(pile))
			return ;
		 if (left + 5 <= right && top2_b(pile) > top3_b(pile))
                        return ;
		swap_a_and_b(pile);
	}
	
}
/*void	compare_3_firstelem(pile *pile, int left, int right)
{
	if (right == left + 2)
	{
		if (top_a(pile) < top2_a(pile) && top2_a(pile) < top3_a(pile))
			return ;
		if (top_a(pile) > top2_a(pile) && top2_a(pile) < top3_a(pile) && top_a(pile) < top3_a(pile))
			swap_a(pile);
		if ()
	}
}*/

void    Sort_a_normal(int *array, pile *pile, int left, int right)
{

        int     m;
        int     i;

	//compare_2_firstelem(pile, left, right);
	if (right == left + 1)
	{
		if (top_a(pile) > top2_a(pile))
			swap_a(pile, 1);
	}
        else if (left < right)
        {
                i = left;
                m = (right + left - 1) / 2;
                while (i <= right)
               	{
                	if (top_a(pile) <= array[m])
                                        push_b(pile);
                        else
                        {
                               rotate(pile->a);
         	               rotate_save_a(pile->cmd);
                        }
                	i++;
                }
		if (pile_size(*(pile->a)) != right - m)
                	Sort_a_reverse(array, pile, m + 1, right);
		else
		{	
			double_swap(pile, left, right);
			Sort_a_normal(array, pile, m + 1, right);
		}
                Sort_b_normal(array, pile, left, m);
        }
}

void	Sort_a_reverse(int *array, pile *pile, int left, int right)
{
	
	int	m;
	int	i;

	
        if (right == left + 1)
        {
		reverserotate(pile->a);
		reverserotate(pile->a);
		reverserotate_save_a(pile->cmd);
		reverserotate_save_a(pile->cmd);
                if (top_a(pile) > top2_a(pile))
                        swap_a(pile, 1);
        }	
	else if (left < right)
	{
		i = left;
		m = (right + left - 1) / 2;
		while (i <= right)
		{
			reverserotate(pile->a);
			reverserotate_save_a(pile->cmd);
			if (top_a(pile) <= array[m])
				push_b(pile);
			i++;
		}
	//	double_swap(pile, left, right);
		Sort_a_normal(array, pile, m + 1, right);
		Sort_b_normal(array, pile, left, m);
	}
	else
	{
		reverserotate(pile->a);
		reverserotate_save_a(pile->cmd);
	}

}

pile	*Createpile()
{
	pile *result;
	
	result = malloc(sizeof(pile));
	result->a = malloc(sizeof(list *));
	result->b = malloc(sizeof(list *));
	*(result->a) = NULL;
	*(result->b) = NULL;
	result->cmd = malloc(sizeof(t_cmd));
	return (result);
}




void	printab(int *a, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", a[i]);
		i++;
	}
}

void	printseparateur()
{
	printf("\n\n=================================================================\n\n");
}


/*int	alreadysorted(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if (*argv)
	{
		while (argv[i] < argv[j])
		{
			if (atoi(argv[i]) > atoi(argv[j]))
				return (0);
			i++;
			j++;
		}
		printf("");
	}
	return (0);
}*/

/*char	**parsing_args(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = -1;
		while (av[++i][++j])
		{
			if (((!ft_isdigit(av[i][j]) && (av[i][j] != '-' && av[i][j] != '+'))
			|| (av[i][j] == '-' && (!ft_isdigit(av[i][j + 1]))) || ((av[i][j] == '-'
			|| av[i][j] == '+') && (av[i][j + 1] == '+'
			|| av[i][j + 1] == '-'))))
			{
				printf("Error\n");
				extit();
			}
		}
	}
	return (av + 1);
}*/

int main(int ac, char **av)
{
	pile	*pile;
	int	*array;
	int	i;
	int	j;
	char **args;
	
/*	if (ac > 2)
	{
		args = parsing_args(ac, av);
	}*/
	pile = Createpile();
	j = 1;
	i = 0;
	array = malloc(sizeof(int) * (ac - 1));
	j = 1;
	while (j < ac)
		array[i++] = atoi(av[j++]);
	j = ac - 2;
	i = 0;
	while (j >= 0)
		push(pile->a, array[j--]);
	pile->total_size = ac - 1;
	sortarray(array, ac - 1);
	Sort_a_normal(array, pile, 0, ac - 2);
//	print(pile->a);
	while (!isEmpty(pile->a))
	{
		pop(pile->a);
	}
//	free(pile->cmd);
//	free(pile);
//	system("leaks a.out");
	return 0;
	
}
