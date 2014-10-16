/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 19:31:45 by tseguier          #+#    #+#             */
/*   Updated: 2014/10/16 09:38:47 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_readarg.h"
#include "libft.h"

int		ft_printf(char *format, ...)
{
	va_list			args;
	int				index;
	ULONG			size;
	t_printf_arg	arg;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
				arg = ft_getarg(&index, format);
				size += ft_printarg(arg, format, &args);
		}
		else
		{
			ft_putchar(format[index++]);
			++size;
		}
	}
	va_end(args);
	return (size);
}

int		ft_sprintf(char *out, char *format, ...)
{
	va_list			args;
	int				index;
	ULONG			size;
	t_printf_arg	arg;

	size = 0;
	index = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%' && format[++index] != '%')
		{
				arg = ft_getarg(&index, format);
				arg.output = out + size;
				size += ft_printarg(arg, format, &args);
		}
		else
		{
			out[size++] = format[index++];
		}
	}
	out[size] = '\0';
	va_end(args);
	return (size);
}
