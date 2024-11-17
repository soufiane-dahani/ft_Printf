/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:00:12 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/17 15:53:55 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, len);
	ft_putchar((n % 10) + '0', len);
}

int	ft_printf(const char *format, ...)
{
	int				len;
	va_list			args;
	int				n;
	char			*str;
	char			c;
	void			*ptr;
	unsigned int	num;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				n = va_arg(args, int);
				ft_putnbr(n, &len);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				ft_putstr(str, &len);
			}
			else if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				ft_putchar(c, &len);
			}
			else if (*format == 'p')
			{
				ptr = va_arg(args, void *);
				ft_putptr(ptr, &len);
			}
			else if (*format == 'x')
			{
				num = va_arg(args, unsigned int);
				ft_puthex(num, 0, &len);
			}
			else if (*format == 'X')
			{
				num = va_arg(args, unsigned int);
				ft_puthex(num, 1, &len);
			}
			else if (*format == 'u')
			{
				num = va_arg(args, unsigned int);
				ft_putnbr_unsigned(num, &len);
			}
			else if (*format == '%')
			{
				ft_putchar('%', &len);
			}
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
int	main(int argc, char const *argv[])
{
	//unsigned int num = 4294967295;
	int len;
	len = ft_printf("%%");
	ft_printf("\n%d\n", len);
	len = printf("%%");
	printf("\n%d\n", len);
	return (0);
}
