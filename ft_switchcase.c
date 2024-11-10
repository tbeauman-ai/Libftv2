/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:55:48 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/10 14:48:12 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	cc;

	if (c < 0 && c > 256)
		return (0);
	if (c == -1)
		return (-1);
	cc = (unsigned char)c;
	if (cc >= 'a' && cc <= 'z')
		cc -= 32;
	return ((int)cc);
}

int	ft_tolower(int c)
{
	unsigned char	cc;

	if (c < 0 && c > 256)
		return (0);
	if (c == -1)
		return (-1);
	cc = (unsigned char)c;
	if (cc >= 'A' && cc <= 'Z')
		cc += 32;
	return ((int)cc);
}
