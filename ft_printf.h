/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:06:04 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/11 18:33:23 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

void		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_put_char(va_list list, int *count);
void		ft_put_nbr(va_list list, int *count);
void		ft_put_str(va_list list, int *count);
void		ft_putnbru(unsigned int n);
void		ft_put_unsigned(va_list list, int *count);
void		ft_convert(va_list list, char c, int *count);
void		ft_put_ptr(va_list list, int *count);
void		ft_check_flag(va_list list, int *count, char c);
int			ft_printf(const char *format, ...);
int			ft_base2(char *res, unsigned int n);
int			ft_base(char *res, unsigned long n);

#endif
