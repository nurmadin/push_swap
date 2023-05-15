/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:52:59 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/15 20:33:22 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_if_sorted(t_list *stack)
{
    t_list *elem;
    
    elem = stack;
    while (elem->next != NULL)
    {
        if (elem->data > elem->next->data)
            return (1);
        elem = elem->next;
    }
    return (0);
}

int max_value(t_list *stack)
{
    t_list *elem;
    int max;

    elem = stack;
    max = stack->data;
    while (elem != NULL)
    {
        if (elem->data > max)
            max = elem->data;
        elem = elem->next;
    }
    return (max);
}

int min_value(t_list *stack)
{
    t_list *elem;
    int min;

    elem = stack;
    min = stack->data;
    while (elem != NULL)
    {
        if (elem->data < min)
            min = elem->data;
        elem = elem->next;
    }
    return (min);
}

/* function that sorts when there are only three elements left in stack A */
void    sort_three(t_list **stack_a)
{
    if (check_if_sorted(*stack_a))
    {
        if ((*stack_a)->data == min_value(*stack_a))
        {
            rra(stack_a);
            sa(stack_a);
        }
        else if ((*stack_a)->data == max_value(*stack_a))
        {
            ra(stack_a);
            if (check_if_sorted(*stack_a))
                sa(stack_a);
        }
        else
        {
            if (((*stack_a)->next->data) == min_value(*stack_a))
                sa(stack_a);
            else 
                rra(stack_a);
        }
    }
}

// void print(t_list *list)
// {
//     while (list != NULL)
//     {
//         printf("%d ", list->data);
//         list = list->next;
//     }
//     printf("\n");
// }

// int main(int argc, char **argv)
// {
//     t_list *stack_a;
    
//     int i;
//     t_list *node;
    
//     stack_a = NULL;
    
//     i = 1;
//     while (i < argc)
//     {
//         node = ft_lstnew(ft_atoi(argv[i]));
//         ft_lstadd_back(&stack_a, node);
//         i++;
//     }
    
//     printf("Before:\n");
//     printf("a: ");
//     print(stack_a);
    
//     sort_three(&stack_a);

//     printf("\nAfter:\n");
//     printf("a: ");
//     print(stack_a);

//     return (0);
// }