/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listiter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:27:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/08 16:33:08 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *head;

    head = NULL;
    while (lst)
    {
        ft_lstadd_front(&head, f(lst->content));
        lst = lst->next;
    }
    return (head);
}