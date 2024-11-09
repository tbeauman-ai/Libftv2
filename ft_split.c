/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:20:25 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/09 18:02:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len_word(const char *str, int i, char c)
{
	int		ret;

	ret = 0;
	while (str[i] != c && str[i])
	{
		i++;
		ret++;
	}
	return (ret);
}

int	count_words(const char *str, char c)
{
	int		r;
	int		i;

	r = 0;
	i = 0;
	if (str[i] == c)
		while (str[i] && str[i] == c)
			i++;
	while (str[i])
	{
		if (str[i + 1] == '\0' && str[i] != c)
			r++;
		if (str[i] == c)
		{
			r++;
			while (str[i + 1] == c)
			{
				i++;
			}
		}
		i++;
	}
	return (r);
}

char		**ft_split(const char *str, char c)
{
	int		i;
	int		nw;
	int		l;
	char	**res;

	if (!str || !*str)
	{
		res = (char **)malloc(sizeof(char *) * 1);
		if (!res)
			return (0);
		res[0] = 0;
		return (res);
	}

	res = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	nw = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			l = 0;
			res[nw] = (char *)malloc(sizeof(char) * (len_word(str, i, c) + 1));
			if (!res[nw])
			{
				while (l < nw)
					free(res[l++]);
				free(res);
				return (NULL);
			}
			while (str[i] != c && str[i])
				res[nw][l++] = str[i++];
			res[nw++][l] = '\0';
		}
	}
	res[nw] = NULL;
	return (res);
}
/*
char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		i;
	int		j;
	int	n_word;

	ret = NULL;
	if (!str || !*str)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		if (!ret)
			return (0);
		ret[0] = 0;
		return (ret);
	}
	

	i = 0;
	n_word = 0;
	ret = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!ret)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == c))
				j++;
			ret[n_word] = ft_strndup(str + i, j);
			if (!ret[n_word++])
				return (0);
			i = i + j;
		}
	}
	ret[n_word] = 0;
	return (ret);

}*/