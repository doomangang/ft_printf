/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/16 15:01:39 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ptr;
	const char	*str;
	int			cnt;
	int			len;

	cnt = 0;
	len = 0;
	va_start(ptr, fmt);
	str = fmt - 1;
	while (*(++str))
	{
		if (*str != '%')
			len = ft_putchar(*str);
		else
		{
			len = format_printer(str, ptr);
			str++;
		}
		if (len == -1)
			return (-1);
		cnt += len;
	}
	va_end(ptr);
	return (cnt);
}

int	format_printer(const char *s, va_list p)
{
	char	c;
	int		len;

	c = *(s + 1);
	if (c == 'c')
		len = ft_putchar(va_arg(p, int));
	if (c == 's')
		len = ft_putstr(va_arg(p, char *));
	if (c == 'p')
	{
		len = ft_putstr("0x");
		len += ft_put_unbr(va_arg(p, unsigned long long), "0123456789abcdef");
	}
	if (c == 'd' || c == 'i')
		len = ft_put_nbr((long long)va_arg(p, int), "0123456789");
	if (c == 'u')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789");
	if (c == 'x')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		len = ft_putchar('%');
	p++;
	return (len);
}

int	ft_put_uint(unsigned int n, char *base)
{
	int					len;
	unsigned long long	nbr;

	nbr = (unsigned long long)n;
	len = ft_put_unbr(nbr, base);
	return (len);
}
