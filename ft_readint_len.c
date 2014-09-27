#include "ft_readformat.h"

int	ft_zlen(t_printf_arg *arg)
{
    arg->len = PRINTF_ZLEN;
    arg->state = STATE_ZLEN;
    return (0);
}

int	ft_hlen(t_printf_arg *arg)
{
	arg->len = PRINTF_HLEN;
	arg->state = STATE_HLEN;
	return (0);
}

int	ft_hhlen(t_printf_arg *arg)
{
	arg->len = PRINTF_HHLEN;
	arg->state = STATE_HHLEN;
	return (0);
}

int	ft_llen(t_printf_arg *arg)
{
	arg->len = PRINTF_LLEN;
	arg->state = STATE_LLEN;
	return (0);
}

int	ft_lllen(t_printf_arg *arg)
{
	arg->len = PRINTF_LLLEN;
	arg->state = STATE_LLLEN;
	return (0);
}

