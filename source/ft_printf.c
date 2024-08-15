/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:24:13 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/05/03 11:22:49 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_base2(char *res, unsigned int n)
{
	char	*charset;
	int		i;

	charset = "0123456789abcdef";
	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n != 0)
	{
		res[i++] = charset[n % 16];
		n = n / 16;
	}
	return (i);
}

int	ft_base(char *res, unsigned long n)
{
	char			*charset;
	int				i;

	charset = "0123456789abcdef";
	i = 0;
	while (n != 0)
	{
		res[i++] = charset[n % 16];
		n = n / 16;
	}
	return (i);
}

void	ft_put_ptr(va_list list, int *count)
{
	char			res[20];
	unsigned long	n;
	int				i;

	n = va_arg(list, unsigned long);
	i = ft_base(res, n);
	*count += i;
	i--;
	write(1, "0x", 2);
	if (n == 0 && i < 0)
	{
		(*count)++;
		write(1, "0", 1);
	}
	*count = *count + 2;
	while (i >= 0)
	{
		ft_putchar_fd(res[i--], 1);
	}
}

void	ft_check_flag(va_list list, int *count, char c)
{
	if (c == 'c')
		ft_put_char(list, count);
	else if (c == 'd' || c == 'i')
		ft_put_nbr(list, count);
	else if (c == 'u')
		ft_put_unsigned(list, count);
	else if (c == 's')
		ft_put_str(list, count);
	else if (c == 'x' || c == 'X')
		ft_convert(list, c, count);
	else if (c == 'p')
		ft_put_ptr(list, count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	list;
	int		count;

	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_flag(list, &count, format[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
		}
	}
	va_end(list);
	return (count);
}
