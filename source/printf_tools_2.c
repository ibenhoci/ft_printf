/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:30:00 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/05/03 11:19:11 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_nbr(va_list list, int *count)
{
	int	d;

	d = va_arg(list, int);
	ft_putnbr_fd(d, 1);
	if (d <= 0)
		(*count)++;
	while (d)
	{
		d = d / 10;
		(*count)++;
	}
}

void	ft_putnbru(unsigned int n)
{
	char			c;

	if (n >= 10)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_put_unsigned(va_list list, int *count)
{
	unsigned int	u;

	u = va_arg(list, unsigned int);
	ft_putnbru(u);
	if (u == 0)
		(*count)++;
	while (u)
	{
		u = u / 10;
		(*count)++;
	}
}

void	ft_put_str(va_list list, int *count)
{
	char	*s;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
	}
}

void	ft_convert(va_list list, char c, int *count)
{
	int				i;
	unsigned int	n;
	char			res[10];

	n = va_arg(list, unsigned int);
	i = ft_base2(res, n);
	*count += i;
	i--;
	while (i >= 0)
	{
		if (c == 'X')
		{
			if (res[i] >= 'a' && res[i] <= 'f')
				res[i] -= 32;
		}
		ft_putchar_fd(res[i--], 1);
	}
}
