/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:44 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/06 14:19:59 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     is_in_set(char c, char const *set)
{
    int     i;

    i = 0;
    while(set[i])
    {
        if (set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *ret;
    int     i;
    int     j;

    ret = (char *)malloc(sizeof(char) * ft_strlen(s1));
    ft_bzero(ret, ft_strlen(s1));
    if (!ret)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[j])
    {
        if (!is_in_set(s1[j], set))
            ret[i++] = s1[j];
        j++;
    }
    return (ret);
}