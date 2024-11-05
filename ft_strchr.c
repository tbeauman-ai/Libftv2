/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:32:03 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/05 13:36:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s += 1;
	}
	if ((char)c == '\0')
		return ((char*)s);
	else
		return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    while (i)
    {
        if (s[i] == (char)c)
            return ((char *)(s + i));
        i--;
    }
	return (NULL);
}
