/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/15 23:41:41 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ptr;
	const char	*str;
	int			err;
	int			cnt;

	cnt = 0;
	va_start(ptr, fmt);
	str = fmt - 1;
	while (*(++str))
	{
		if (err == -1)
			return (-1);
		if (*str != '%')
		{
			cnt += ft_putchar(*str, &err);
			continue ;
		}
		cnt += format_printer(str, ptr, &err);
		str++;
	}
	va_end(ptr);
	return (cnt);
}

int	format_printer(const char *s, va_list p, int *err)
{
	char	c;
	int		len;

	c = *(s + 1);
	if (c == 'c')
		len = ft_putchar(va_arg(p, int), err);
	if (c == 's')
		len = ft_putstr(va_arg(p, char *), err);
	if (c == 'p')
	{
		len = ft_putstr("0x", err);
		len += ft_put_unbr(va_arg(p, unsigned long long), "0123456789abcdef", err);
	}
	if (c == 'd' || c == 'i')
		len = ft_put_nbr((long long)va_arg(p, int), "0123456789", err);
	if (c == 'u')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789", err);
	if (c == 'x')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789abcdef", err);
	if (c == 'X')
		len = ft_put_uint(va_arg(p, unsigned int), "0123456789ABCDEF", err);
	if (c == '%')
		len = ft_putchar('%', err);
	p++;
	return (len);
}

int	ft_put_uint(unsigned int n, char *base, int *err)
{
	int					len;
	unsigned long long	nbr;

	nbr = (unsigned long long)n;
	len = ft_put_unbr(nbr, base, err);
	return (len);
}
