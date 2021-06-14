#ifndef FT_PRINTFN_H
# define FT_PRINTFN_H
# include "ft_printf.h"

int	ft_print_hex(t_mask *mask, va_list *arg, int fd);

int	ft_print_string(t_mask *mask, va_list *arg, int fd);

int	ft_print_integer(t_mask *mask, va_list *arg, int fd);

int	ft_print_unsigned(t_mask *mask, va_list *arg, int fd);

int	ft_print_precent(t_mask *mask, va_list *arg, int fd);

#endif