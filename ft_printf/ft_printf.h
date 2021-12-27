/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-du <xle-du@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:59:48 by xle-du            #+#    #+#             */
/*   Updated: 2021/05/12 13:28:40 by xle-du           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_display_settings
{
	int	width;
	int	precision;
}				t_display_settings;

typedef struct s_settings
{
	int	flag_zero;
	int	flag_minus;
	int	width;
	int	precision;
	int	error;
}				t_settings;

/*
** UTILS
*/
void			ft_putnbr_base(unsigned long long nbr, char *base,
					size_t *count);
void			ft_putnbr_u(unsigned int nb, size_t *count);
void			ft_putstr(char *s, size_t *count);
void			ft_putchar(char c, size_t *count);
size_t			ft_strlen_pf(const char *s);

/*
** UTILS 2
*/
void			ft_putnbr(int n, size_t *count);
int				ft_isdigit(int c);
int				ft_isconversion(int c);
void			ft_putchar_c(char c, int size, size_t *count);
void			ft_putstr_prec(char *s, int precision, size_t *count);

/*
** UTILS 3
*/
void			display_str(char *str, t_settings settings,
					t_display_settings dsettings, size_t *count);
void			display_p(char *str, t_settings settings, size_t *count);
void			display_d(char *nombre, int negative,
					t_settings settings, size_t *count);
void			display_x(char *str, t_settings settings, size_t *count);

/*
** UTILS 4
*/
int				count_nb(long nb);
char			*ft_itoa_pf(int nb);
char			*ft_itoa_u(unsigned int nb);
void			ft_putstr_prec_p(char *s, int precision, size_t *count);
void			ft_putstr_prec_d(char *nombre, int	precision, size_t *count);

/*
** UTILS 5
*/
char			*ft_itoa_hexa(unsigned long long nb, char *base);

/*
** UTILS_P
*/
void			ft_put_p_case1(char *s, t_settings settings,
					int size, size_t *cnt);
void			ft_put_p_case2(char *s, t_settings settings,
					int size, size_t *cnt);
void			ft_put_p_case3(char *s, t_settings settings,
					size_t *cnt);
void			ft_put_p_case4(char *s, t_settings settings,
					size_t *cnt);
void			ft_put_p_case5(char *s, t_settings settings,
					int size, size_t *cnt);

/*
** CONVERSION
*/
void			ft_print_char(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_string(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_address(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_nbr(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_unsigned(va_list valist, size_t *count,
					t_settings settings);

/*
** CONVERION 2
*/
void			ft_print_hexa_lower(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_hexa_upper(va_list valist, size_t *count,
					t_settings settings);
void			ft_print_percent(size_t *count, t_settings settings);

/*
** PARSE
*/
int				parse_conversion(va_list valist, char *str, size_t *count);
int				parse(va_list valist, char *str);

/*
** PARSE SETTINGS
*/
void			parse_settings_flags(char *str,
					size_t *index, t_settings *settings);
void			parse_settings_width(va_list valist, char *str,
					size_t *index, t_settings *settings);
void			parse_settings_precision(va_list valist, char *str,
					size_t *index, t_settings *settings);
t_settings		parse_settings(va_list valist, char *str, size_t *index);

/*
** INIT STRUCT SETTINGS
*/
t_settings		ft_init_settings(void);

/*
** PRINTF
*/
int				ft_printf(int fd, const char *format,
					...) __attribute__((format(printf, 2, 3)));

#endif
