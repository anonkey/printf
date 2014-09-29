/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 20:29:24 by tseguier          #+#    #+#             */
/*   Updated: 2014/09/29 20:46:59 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_len(long long nbr, int sign, int width, char fill)
{
	int			size;
	char		strout[MAX_LLSIZE + 1];
	char		*act;

	size = 1;
	act = strout + MAX_LLSIZE;
	*act-- = '\0';
	if (nbr < 0 || sign)
	{
		++size;
		sign = nbr < 0 ? '-' : '+';
		nbr = nbr > 0 ? nbr : 0 - nbr;
	}
	while (nbr >= 10)
	{
		*act-- = '0' + (char)(nbr % 10);
		nbr /= 10;
		++size;
	}
	*act = '0' + nbr;
	if (sign)
		*--act = sign;
	while (++size <= width)
		*--act = fill;
	return (ft_putstr(act));
}
