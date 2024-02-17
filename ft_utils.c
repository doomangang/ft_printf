/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/17 19:30:45 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_printer(char *s)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	if (!s)
		return (str_printer("(null)"));
	while (*(s + len))
		len++;
	if (write(1, s, len) != len)
		len = -1;
	return (len);
}

int	pointer_printer(unsigned long long n, char *base)
{
	int base_len;
	int	len;
	int	cnt;

	cnt = str_printer("0x");
	if (cnt == -1)
		return (-1);
	len = cnt;
	base_len = 0;
	while (*(base + base_len))
		base_len++;
	len += display(n, base, base_len);
	if (len == -1)
		return (-1);
	return (len);
}

int	num_printer(long long n, char *base)
{
	int	base_len;
	int	len;

	base_len = 0;
	len = 0;
	while (*(base + base_len))
		base_len++;
	if (n < 0)
	{
		if (char_printer('-') == -1)
			return (-1);
		n *= -1;
		len++;
	}
	len += display(n, base, base_len);
	if (len <= 0)
		return (-1);
	return (len);
}

int	unsigned_printer(unsigned int n, char *base)
{
	unsigned long long	num;
	int					base_len;
	int					len;

	num = (unsigned long long)n;
	base_len = 0;
	len = 0;
	while (*(base + base_len))
		base_len++;
	len = display(num, base, base_len);
	if (len == -1)
		return (-1);
	return (len);
}

int	display(unsigned long long n, char *base, int base_len)
{
	int	len;
	int	cnt;

	len = 0;
	if (n >= (unsigned long long)base_len)
	{
		cnt = display(n / base_len, base, base_len);
		if (cnt == -1)
			return (-1);
		len += cnt;
	}
	if (char_printer(base[n % base_len]) == -1)
		return (-1);
	len++;
	return (len);
}
