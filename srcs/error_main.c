/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:45:26 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/05/01 17:34:41 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

int temp_error_check(char **temp)
{
    int i;
    int size;
    
    i = 0;
    size = 0;
    while (temp[size] != 0)
        size++;
    while (temp[i] != 0)
    {
        if (digit_check(temp[i]) == 1 || range_check(temp[i]) == 1)
            return (1);
        i++;
    }
    if (dup_check(size, temp, 2) == 1)
        return (1);
    return (0);
}

int argv_error_check(int argc, char **argv)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        if (digit_check(argv[i]) == 1 || range_check(argv[i]) == 1)
            return (1);
        i++;
    }
    if (dup_check(argc, argv, 1) == 1)
        return (1);
    return (0);
}

// error_check function checks 
int error_check(int argc, char **argv)
{
    char **temp;
    int flag;
    
    flag = 0;
    if (argc == 2)
    {
        temp = ft_split(argv[1], ' '); 
        flag = temp_error_check(temp);
        ft_free_arr(temp);
        free(temp);
    }
    else
        flag = argv_error_check(argc, argv);
    return (flag);
}

// int main(int argc, char **argv)
// {
//     // if 0 it means no error, if 1 it means error
//     printf("{%d}", error_check(argc, argv));
//     return (0);
// }
