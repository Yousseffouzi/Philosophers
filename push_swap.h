/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:17:59 by root              #+#    #+#             */
/*   Updated: 2025/04/07 14:18:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// split
char				*ft_substr(const char *str, unsigned int start, size_t n);
char				**ft_split(const char *s, char c);
char				**ft_free(char **str);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t num, size_t size);

// check
int					check_sort(t_list *a);
int					check_dup(t_list *a);
void				ft_error(t_list **a, char **av);

// linked_list.c
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);

// operation
void				pb(t_list **a, t_list **b, int flag);
void				pa(t_list **a, t_list **b, int flag);

void				sa(t_list **a, int flag);
void				sb(t_list **b, int flag);
void				ss(t_list **a, t_list **b, int flag);

void				ra(t_list **a, int flag);
void				rb(t_list **b, int flag);
void				rr(t_list **a, t_list **b, int flag);

void				rra(t_list **a, int flag);
void				rrb(t_list **b, int flag);
void				rrr(t_list **a, t_list **b, int flag);

// arr
int					*sorted(t_list *a);

// fill_stack
void				fill_stack(t_list **a, char **av);

// sort_algo
void				sort_3(t_list **a);
void				sort_5(t_list **a, t_list **b);
void				sort_all(t_list **a, t_list **b, int *arr, int size);

#endif
