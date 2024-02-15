/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:15:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/15 23:39:48 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int *err)
{
	if (write(1, &c, 1) == -1)
		*err = -1;
	return (1);
}

int	ft_putstr(char *s, int *err)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	if (!s)
		return (ft_putstr("(null)", err));
	while (*(s + len))
		len++;
	while (idx != len)
	{
		ft_putchar(*s, err);
		s++;
		idx++;
	}
	return (len);
}

int	ft_put_nbr(long long nbr, char *base, int *err)
{
	int	nob;
	int	len;

	nob = 0;
	len = 0;
	while (*(base + nob))
		nob++;
	if (nbr < 0)
	{
		ft_putchar('-', err);
		nbr *= -1;
		len++;
	}
	len += display(nbr, base, nob, err);
	return (len);
}

int	ft_put_unbr(unsigned long long nbr, char *base, int *err)
{
	int	nob;
	int	len;

	nob = 0;
	len = 0;
	while (*(base + nob))
		nob++;
	len += display(nbr, base, nob, err);
	return (len);
}

int	display(unsigned long long nbr, char *base, int nob, int *err)
{
	int	len;

	len = 0;
	if (nbr >= (unsigned long long)nob)
		len += display(nbr / nob, base, nob, err);
	ft_putchar(base[nbr % nob], err);
	len++;
	return (len);
}
