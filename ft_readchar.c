#include "ft_readformat.h"

int	ft_chartype(t_printf_arg *arg)
{
    arg->type = arg->act;
    arg->state = STATE_END;
    return (0);
}

int		ft_printf_char(t_printf_arg *arg, char *format, va_list *args_p)
{
    char    c;

    (void)format;
    c = (char)va_arg(*args_p, int);
    if (arg->flags == 0)
        return (ft_putchar(c));
    return (0);
}
