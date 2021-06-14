#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# define ASCII_MAX 128

typedef struct s_wrapper
{
	intmax_t	sym_amnt;
	char		padding_sym;
	char		sign[2];
	intmax_t	pr_sym_amnt;
}				t_wrapper;

typedef struct s_length
{
	bool		l : 1;
	bool		ll : 1;
	bool		h : 1;
	bool		hh : 1;
}				t_length;

typedef struct s_mask
{
	bool		alternative_mode : 1;
	bool		left_align : 1;
	bool		frnt_spc : 1;
	bool		print_sign : 1;
	bool		uppercase : 1;
	bool		is_negative : 1;
	bool		prec : 1;
	int32_t		width;
	int32_t		precision;
	int32_t		symbols_printed;
	char		specifier;
	t_wrapper	wrapper;
	t_length	length;
}				t_mask;

typedef int	(*t_printfn) (t_mask *mask, va_list *arg, int fd);

int		ft_printf(const char *frmt_str, ...);

int		ft_marshal_format(
			const char *frmt_str, t_mask *mask, va_list *arg_list);

int		ft_print_caller(t_mask *mask, va_list *arg_list, int fd);

void	init_mask(t_mask *mask);
#endif