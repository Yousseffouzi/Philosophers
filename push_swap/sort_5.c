/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:57:51 by root              #+#    #+#             */
/*   Updated: 2025/04/07 10:57:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     small_node(t_list *a)
{
    t_list  *curr;
    int     curr_pos;
    int     min_value;
    int     min_pos;

    curr = a;
    curr_pos = 1;
    min_pos = 1;
    min_value = a->content;
    while(curr)
    {
        if (curr->content < min_value)
        {
            min_value = curr->content;
            min_pos = curr_pos;
        }
        curr = curr->next;
        curr_pos++;
    }
    return (min_pos);
}

void    sort_5(t_list **a, t_list **b)
{
    int     i;

    while(ft_lstsize(*a) > 3)
    {
        i = small_node(*a);
        if (small_node(*a) <= (ft_lstsize(*a) / 2) + 1)
        {
            while(i > 1)
            {
                ra(a, 0);
                i--;
            }
        }
        else
        {
            while(i++ <= ft_lstsize(*a))
                rra(a, 0);
        }
    }
    sort_3(a);
    pa(a, b, 0);
    if ((*b))
        pa(a, b, 0);
}
