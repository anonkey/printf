#include "ft_readformat.h"

int	ft_dllen(t_printf_arg *arg)
{
	arg->len = PRINTF_DLLEN;
	arg->state = STATE_DLLEN;
	return (0);
}
