/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:29 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/08 16:26:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst)
    {
        del(lst->content);
        free(lst);
        lst = NULL;
    }
}

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *head;
    t_list  *tmp;

    head = *lst;
    while (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        lst = tmp;
    }
    head = NULL;
}