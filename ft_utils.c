/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/16 15:02:57 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*(s + len))
		len++;
	if (write(1, s, len) != len)
		len = -1;
	return (len);
}

int	ft_put_nbr(long long nbr, char *base)
{
	int	nob;
	int	len;

	nob = 0;
	len = 0;
	while (*(base + nob))
		nob++;
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nbr *= -1;
		len++;
	}
	len += display(nbr, base, nob);
	if (len <= 0)
		return (-1);
	return (len);
}

int	ft_put_unbr(unsigned long long nbr, char *base)
{
	int	nob;
	int	len;

	nob = 0;
	len = 0;
	while (*(base + nob))
		nob++;
	len = display(nbr, base, nob);
	if (len == -1)
		return (-1);
	return (len);
}

int	display(unsigned long long nbr, char *base, int nob)
{
	int	len;
	int	cnt;

	len = 0;
	if (nbr >= (unsigned long long)nob)
	{
		cnt = display(nbr / nob, base, nob);
		if (cnt == -1)
			return (-1);
		len += cnt;
	}
	if (ft_putchar(base[nbr % nob]) == -1)
		return (-1);
	len++;
	return (len);
}
