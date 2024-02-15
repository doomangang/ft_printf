/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/15 20:44:58 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;
	int idx;

	len = 0;
	idx = 0;
	if (!s)
		return (0);
	while (*(s + len))
		len++;
	while (idx != len)
	{
		write(1, s++, 1);
		idx++;
	}
	return (len);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	nob;
	int	len;

	nob = 0;
	len = 0;
	nbr = (long long)nbr;
	while (*(base + nob))
		nob++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		len++;
	}
	len += display(nbr, base, nob);
	return (len);
}

int	display(long long nbr, char *base, int nob)
{
	int	len;

	len = 0;
	if (nbr >= nob)
		len += display(nbr / nob, base, nob);
	write(1, &base[nbr % nob], 1);
	len++;
	return (len);
}

int	ft_putunsigned(unsigned long long nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
		ft_putunsigned(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	len++;
	return (len);
}
