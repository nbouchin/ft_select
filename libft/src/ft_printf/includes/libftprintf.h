/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:21:37 by nbouchin          #+#    #+#             */
/*   Updated: 2017/03/16 09:30:52 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "../../../includes/libft.h"

typedef struct		s_flag
{
	int				precision;
	int				prec;
	int				minus;
	int				plus;
	int				space;
	int				sharp;
	int				zero;
	int				width;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_length;
}					t_flag;

/*
**	specifier functions
*/

int					parser(char **format, t_flag *flag, va_list *arg);
int					get_specifier(char **format, t_flag *flag, va_list *arg);
int					lower_s(va_list *arg, t_flag *flag);
int					upper_s(va_list *arg, t_flag *flag);
int					lower_i(va_list *arg, t_flag *flag);
int					lower_d(va_list *arg, t_flag *flag);
int					upper_d(va_list *arg, t_flag *flag);
int					lower_p(va_list *arg, t_flag *flag);
int					lower_o(va_list *arg, t_flag *flag);
int					upper_o(va_list *arg, t_flag *flag);
int					lower_u(va_list *arg, t_flag *flag);
int					upper_u(va_list *arg, t_flag *flag);
int					lower_x(va_list *arg, t_flag *flag);
int					upper_x(va_list *arg, t_flag *flag);
int					lower_c(va_list *arg, t_flag *flag);
int					upper_c(va_list *arg, t_flag *flag);
int					modulo(va_list *arg, t_flag *flag);
int					undefined(char c, t_flag *flag);

/*
**	tab and width gesture
*/

void				get_option(char **str, t_flag *flag, va_list *arg);
void				get_flag(char **str, t_flag *flag, va_list *arg);
void				get_width(char **str, t_flag *flag, va_list *arg);
void				get_precision(char **str, t_flag *flag, va_list *arg);
void				get_length(char **str, t_flag *flag, va_list *arg);

/*
**	utils functions
*/

uintmax_t			get_utype(va_list *arg, t_flag *flag);
intmax_t			get_type(va_list *arg, t_flag *flag);
void				reset_flag(t_flag *flag);
void				ft_putnstr(char *str, int n);
int					ft_strnlen(char *str, int n);
int					wchar_len(wchar_t c);
int					wstr_len(wchar_t *s);
int					wstr_nlen(wchar_t *s, int n);
void				ft_putwchar(wchar_t c);
void				ft_putnwstr(wchar_t *s, int n);
void				put_space(int width, int strlen);
void				put_zero(int width, int strlen);
void				get_int(intmax_t nb);
int					get_len(intmax_t nb);
int					get_flag_len(intmax_t nb, t_flag *flag);
void				get_ui(uintmax_t nb, char *str, int base);
int					get_ui_len(uintmax_t nb, int base);
int					get_ui_flag_len(uintmax_t nb, t_flag *flag, int base);
void				put_int_left_space(t_flag *flag, int len, intmax_t nb);
void				put_uint_left_space(t_flag *flag, int len,
					uintmax_t nb, int type);
void				put_str_left_space(t_flag *flag, int len);

#endif
