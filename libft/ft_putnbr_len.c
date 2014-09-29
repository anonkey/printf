#include "libft.h"

int	ft_putnbr_len(long long nbr, int sign, int width, char fill)
{
	int		size;
	char		strout[MAX_LLSIZE + 1];
	char		*act;

// long max
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
		*act = '0' + (char)(nbr % 10);
		--act;
		++size;
		nbr /= 10;
	}
	*act = '0' + nbr;
	if (sign)
	    *--act = sign;
	while (++size <= width)
	{
	    *--act = fill;
	}
	ft_putstr(act);
	return (size - 1);
}