#include "ft_printf.h"

void	ft_print_integer(t_mask *mask, va_list *arg, int fd)
{

}

void	ft_print_hex(t_mask *mask, va_list *arg, int fd)
{

}

void	ft_print_string(t_mask *mask, va_list *arg, int fd)
{

}

void	ft_print_unsigned(t_mask *mask, va_list *arg, int fd)
{

}

t_printfn	get_print_fn(t_mask *mask)
{
	static *t_printfn[ASCII_MAX] = {
		['d'] = ft_print_integer,
		['x'] = ft_print_hex,
		['s'] = ft_print_string,
		['u'] = ft_print_unsigned,
		['%'] = ft_print_string
	}
}