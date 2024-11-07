/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:38:14 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/07 14:19:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        if (n == -2147483648)
        {
            write(fd, "-2147483648", 11);
            return ;
        }
        write(fd, "-", 1);
        n = -n;
    }
    if (n / 10)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd('0' + n % 10, fd);
}

void    ft_putnbr(int n)
{
    ft_putnbr_fd(n, 1);
}