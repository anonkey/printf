#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_readarg.h"

int	ft_printarg(t_printf_arg arg, char *format, va_list *args_p)
{
	t_printfn	*printfunc;

	//printf("F:%d W:%d P:%d T:%d\n\n\n", arg.flags, arg.width, arg.prec, arg.type);
	if (!(printfunc = ft_getprint_fn(arg.type)))
		return (0);
	return (printfunc->print(&arg, format, args_p));
}

int	ft_writearg(int *index_p, char *format, va_list *args_p)
{
	t_printf_arg	arg;

	if (-1 == (arg.flags = ft_readflags(index_p, format)))
		return (-1);
	if (-1 == (arg.width = ft_readwidth(index_p, format)))
		return (-2);
	if (-2 == (arg.prec = ft_readprec(index_p, format)))
		return (-3);
	if (-1 == ft_readtype(&arg, index_p, format))
		return (-4);
	return (ft_printarg(arg, format, args_p));
}

int	ft_printf(char *format, ...)
{
	va_list		args;
	int		index;
	ULONG		size;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
			size += ft_writearg(&index, format, &args);
		}
		else
		{
			ft_putchar(format[index]);
			++size;
			++index;
		}
	}
	va_end(args);
	return (size);
}

int	main(void)
{
	long	a;
	size_t	toto;

	toto = 203032;
	a = 1000000;
	printf(" \n A%dA", ft_printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %+10zd  %6.6zx %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.11111111, 3.14127));
	printf(" \n A%dA", printf("\n%+hhdtoto |%10.4s| %c%% %012lx  %012lo  %lu %+10zd  %6.6zx %p %f %+.4f %e.i\n", (signed char)'3', "Bonjour\n",'@', a, a, a,toto,toto, (void *)0x100UL, 12.42, 1.111111111, 3.14127));
	ft_printf("\n %p \n", NULL);
	printf("\n %p \n", NULL);
	//printf("\n%%");
	return (0);
}
