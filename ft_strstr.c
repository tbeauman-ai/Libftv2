/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:16:38 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/09 09:44:03 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (ft_strcmp(s2, "") == 0)
		return ((char*)s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1)
		s1++;
	if (*s1)
		return (char *)s1;
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > ft_strlen(s1))
		return (ft_strstr(s1, s2));
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1 &&
			i + ft_strlen(s2) - 1 < n)
	{
		i++;
		s1++;
	}
	if (i + ft_strlen(s2) - 1 == n)
		return (NULL);
	if (*s1)
		return (char *)s1;
	return (NULL);
}
