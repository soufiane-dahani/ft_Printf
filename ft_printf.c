/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:00:12 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/17 16:09:18 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}

static void	handle_format(const char specifier, va_list args, int *len)
{
	if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (specifier == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (specifier == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (specifier == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, len);
	else if (specifier == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, len);
	else if (specifier == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (specifier == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_format(*format, args, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
