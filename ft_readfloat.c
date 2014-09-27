#include "ft_readformat.h"

int	ft_floattype(t_printf_arg *arg)
{
    arg->type = arg->act;
    arg->state = STATE_END;
    return (0);
}

int		ft_printf_float(t_printf_arg *arg, char *format, va_list *args_p)
{
    long double	res;
    int		size;

    (void)format;
    size = 0;
    if (arg->len == 0)
	res = (long double) va_arg(*args_p, double);
    else if (arg->len == PRINTF_DLLEN)
	res = (long double)va_arg(*args_p, long double);
    if (arg->type == 'f')
	size = ft_putldouble(res, arg->prec == -1 ? DEFAULT_FLOAT_PREC : arg->prec, (arg->flags & (1 << ft_strchind(PRINTF_FLAGS, '+'))) ? 1 : 0);
    else if (arg->type == 'e')
	size = ft_putldouble_sci(res, arg->prec == -1 ? DEFAULT_FLOAT_PREC : arg->prec);
    return (size);
}
