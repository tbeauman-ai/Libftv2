/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:04:05 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/06 14:09:51 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ret;

    ret = (char *)malloc(len + 1);
    if (!ret)
        return (NULL);
    i = start;
    while (len--)
    {
        ret[i - start] = s[i];
        i++;
    }
    ret[i - start] = 0;
    return (ret);
}