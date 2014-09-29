#include "libft.h"

int	ft_putnbr_ulen(unsigned long long nbr, int width, char fill)
{
	int		size;
	char		strout[MAX_LLSIZE + 1];
	char		*act;

// long max
	size = 1;
	act = strout + MAX_LLSIZE;
	*act-- = '\0';
	while (nbr >= 10)
	{
		*act = '0' + (char)(nbr % 10);
		--act;
		++size;
		nbr /= 10;
	}
	*act = '0' + nbr;
	while (++size <= width)
	    *--act = fill;
	ft_putstr(act);
	return (size - 1);
}
