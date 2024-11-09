/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:20:25 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/09 08:54:31 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char const *s, unsigned int n)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	while (s[i] && i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			while (!(*str == c))
				str++;
			count++;
		}
	}
	return (count);
}

char	**ft_fill_ret(char **tab, char const *str, char c)
{
	int	i[2];
	int	n_word;

	i[0] = 0;
	n_word = 0;
	tab = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!tab)
		return (0);
	while (str[i[0]] != 0)
	{
		if (str[i[0]] == c)
			i[0]++;
		else
		{
			i[1] = 0;
			while (!(str[i[0] + i[1]] == c))
				i[1]++;
			tab[n_word] = ft_strndup(str + i[0], i[1]);
			if (!tab[n_word++])
				return (0);
			i[0] = i[0] + i[1];
		}
	}
	tab[n_word] = 0;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;

	ret = NULL;
	if (!str || !*str)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		if (!ret)
			return (0);
		ret[0] = 0;
	}
	else
		ret = ft_fill_ret(ret, str, c);
	return (ret);
}