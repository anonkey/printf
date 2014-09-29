#include <unistd.h>
#include "libft.h"

//TODO: width specifier,fill char

static int		ft_printradix(long double nb, int prec, int mask)
{
	char	digit;
	int		size;

	size = prec + 1;
	write(1, ".", 1);
	while (mask >= 1.0)
	{
		digit = (char)(nb / mask);
		++size;
		nb -= mask * (long double)digit;
		mask /= 10.0;
		ft_putchar(digit + '0');
	}
	while (prec > 0)
	{
		if (nb != 0)
		{
			nb *= 10;
			digit = (char)nb;
			nb -= (long double)digit;
			ft_putchar(digit + '0');
		}
		else
			ft_putchar('0');
		--prec;
	}
	return (size);
}

int		ft_putldouble_sci(long double nb, int prec)
{
	int	size;
	int	pow;
	long double	mask;
	char	digit;

	size = 0;
	mask = 1.0;
	pow = 0;
	if (nb < 0)
	{
		nb = 0 - nb;
		write(1, "-", 1);
		++size;
	}
	while (nb / mask > 10.0 && ++pow)
		mask *= 10.0;
	digit = (char)(nb / mask);
	nb -= mask * (long double)digit;
	mask /= 10.0;
	size += ft_putchar(digit + '0');
	if (prec > 0)
		size += ft_printradix(nb, prec, mask);
	size += ft_putchar('e');
	size += ft_putnbr_len(pow, 1, 3, '0');
	return (size);
}
