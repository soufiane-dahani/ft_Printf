/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:00:12 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/17 13:23:38 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	return (len);
}
int	main(int argc, char const *argv[])
{
	int	len;

	len = printf(NULL);
	printf("%d\n", len);
	return (0);
}
