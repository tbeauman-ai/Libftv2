/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:45:24 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/09 18:06:12 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		sign;
	int		i;

	i = 0;
	ret = 0;
	sign = 1;
    while (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == 32)
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

#include "libft.h"

static int	ft_tenpow(unsigned int nb)
{
	if (nb > 0)
		return (10 * ft_tenpow(nb - 1));
	return (1);
}

static int	ft_nb_c(int n)
{
	int		count;

	count = 1;
	if (n > 999999999)
		return (10);
	if (n < -999999999)
		return (11);
	while (n / ft_tenpow(count) != 0)
		count++;
	if (n < 0)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		neg;

	if (n == -2147483648)
	{
		ret = (char *)malloc(sizeof(char) * ft_strlen("-2147483648"));
		ft_memcpy(ret, "-2147483648", ft_strlen("-2147483648"));
		return (ret);
	}
	neg = n < 0 ? 1 : 0;
	ret = (char*)malloc(ft_nb_c(n) + 1);
	i = ft_nb_c(n);
	n = neg == 1 ? -n : n;
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i-- + 1 - neg)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}