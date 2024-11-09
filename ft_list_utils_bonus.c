/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:34:15 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/08 16:40:10 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
    ret->content = (void *)content;
	ret->next = NULL;
	return (ret);
}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}

int     ft_lstlize(t_list *lst)
{
    int     i;

    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

t_list     *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void     ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *head;

    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    head = *lst;
    while ((*lst)->next)
        *lst = (*lst)->next;
    (*lst)->next = new;
    *lst = head;
}