#include "ft_readformat.h"

int	ft_strtype(t_printf_arg *arg)
{
    arg->type = arg->act;
    arg->state = STATE_END;
    return (0);
}

int		ft_printf_str(t_printf_arg *arg, char *format, va_list *args_p)
{
    char    *str;

    (void)format;

    str = va_arg(*args_p, char *);
    if (arg->prec == -1)
        return (ft_putstr(str));
    else
        return (ft_putstr_len(str, arg->prec, arg->width, ' '));
    return (0);
}
