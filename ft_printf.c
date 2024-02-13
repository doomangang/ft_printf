/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/13 19:19:37 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int format_printer(const char *s, va_list p)
{
	char	c;

	c = *(s + 1);
	if (c == 'c')
		return(ft_putchar(va_arg(p, int)));
	return (-1);
}

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
	while (*(str++))
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
