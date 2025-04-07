/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:35:24 by root              #+#    #+#             */
/*   Updated: 2025/04/07 10:35:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     big_node(t_list *a)
{
    t_list  *curr;
    int     curr_pos;
    int     larg_value;
    int     larg_pos;

    curr = a;
    curr_pos = 1;
    larg_pos = 1;
    larg_value = a->content;
    while(curr)
    {
        if (curr->content > larg_value)
        {
            larg_value = curr->content;
            larg_pos = curr_pos;
        }
        curr = curr->next;
        curr_pos++;
    }
    return (larg_pos);
}

void    sort_3(t_list **a)
{
    int     big;

    big = big_node(*a);
    if (big == 3)
    {
        ra(a, 0);
        if (check_sort(*a) == 0)
            sa(a, 0);
    }
    else if (big == 2)
    {
        rra(a, 0);
        if (check_sort(*a) == 0)
            sa(a, 0);
    }
    else
    {
        if (check_sort(*a) == 0)
            sa(a, 0);
    }
}
