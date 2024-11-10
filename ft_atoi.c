/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:45:24 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/10 12:52:28 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;
	int	i;

	i = 0;
	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r'
		|| *str == '\n' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		ret = 10 * ret + (str[i++] - '0');
	return (ret * sign);
}

int	ft_nb_c(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	len;
	char			tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		i;

	neg = (n < 0);
	str = (char *)malloc(sizeof(char) * (ft_nb_c(n) + 1));
	if (!str)
		return (NULL);
	str[ft_nb_c(n)] = 0;
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n != 0)
	{
		str[i] = '0' + ft_abs(n % 10);
		n /= 10;
		i++;
	}
	if (neg)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
