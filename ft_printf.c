/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/15 20:46:05 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ptr;
	const char	*str;
	int			len;
	int			cnt;

	cnt = 0;
	len = 0;
	va_start(ptr, fmt);
	str = fmt - 1;
	while (*(++str))
	{
		if (len < 0)
			break ;
		if (*str != '%')
		{
			len = ft_putchar(*str);
			cnt++;
			continue ;
		}
		len = format_printer(str, ptr);
		cnt += len;
		str++;
	}
	va_end(ptr);
	return (cnt);
}

int	format_printer(const char *s, va_list p)
{
	char	c;
	int		plen;

	c = *(s + 1);
	if (c == 'c')
		plen = ft_putchar(va_arg(p, int));
	if (c == 's')
		plen = ft_putstr(va_arg(p, char *));
	if (c == 'p')
	{
		ft_putstr("0x10");
		plen = ft_putnbr_base((int)(va_arg(p, void *)), "0123456789abcdef") + 4;
	}
	if (c == 'd' || c == 'i')
		plen = ft_putnbr_base(va_arg(p, long long), "0123456789");
	if (c == 'u')
		plen = ft_putunsigned(va_arg(p, unsigned long long));
	if (c == 'x')
		plen = ft_putnbr_base((va_arg(p, long long)), "0123456789abcdef");
	if (c == 'X')
		plen = ft_putnbr_base((va_arg(p, long long)), "0123456789ABCDEF");
	if (c == '%')
		plen = ft_putchar('%');
	p++;
	return (plen);
}
