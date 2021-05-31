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

typedef struct s_mask
{
	bool		alternative_mode : 1;
	bool		left_align : 1;
	bool		frnt_spc : 1;
	bool		print_sign : 1;
	bool		uppercase : 1;
	bool		is_negative : 1;
	int32_t		width;
	int32_t		precision;
	int32_t		symbols_printed;
	char		specifier;
	t_wrapper	wrapper;
	t_length	length;
}				t_mask;

typedef struct s_wrapper
{
	intmax_t	f_sym_amnt;
	intmax_t	b_sym_amnt;
	char		padding_sym;
	char		sign[2];
}				t_wrapper;

typedef struct s_length
{
	bool		l : 1;
	bool		ll : 1;
	bool		h : 1;
	bool		hh : 1;
}				t_length;

int ft_printf(const char *, ...);

int ft_printcontent(const char *, int, int);

#endif