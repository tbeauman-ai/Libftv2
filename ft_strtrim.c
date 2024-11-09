/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:44 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/09 16:50:11 by tbeauman         ###   ########.fr       */
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
    int     start;
    int     end;
    int     i;

    i = 0;
    start = 0;
    end = ft_strlen(s1) - 1;
    while (is_in_set(s1[start], set))
        start++;
    if (start == end + 1)
    {
        ret = (char *)malloc(sizeof(char));
        ret[0] = 0;
        return (ret);
    }
    while (is_in_set(s1[end], set))
        end--;
    ret = (char *)malloc(sizeof(char) * (end - start + 2));
    if (!ret)
        return (NULL);
    ft_bzero(ret, end - start + 2);
    if (!ret)
        return (NULL);
    while (start <= end)
    {
        ret[i] = s1[start];
        i++;
        start++;
    }
    return (ret);
}