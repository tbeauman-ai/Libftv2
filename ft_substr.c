/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:04:05 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/10 12:14:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	end;

	if (start >= ft_strlen(s) || len == 0)
	{
		ret = (char *)malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	end = start + len;
	if (end >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start] && start < end)
		ret[i++] = s[start++];
	ret[i] = 0;
	return (ret);
}
