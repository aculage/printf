#include "ft_printf.h"
#include "ft_printfn.h"

void	ft_polymorph(t_mask *mask)
{
	if (mask->specifier == 'c')
	{
		mask->precision = 1;
		mask->specifier = 's';
	}
	if (mask->specifier == 'p')
	{
		mask->specifier = 'x';
		mask->alternative_mode = true;
	}
	if (mask->specifier == 'X')
	{
		mask->uppercase = true;
		mask->specifier = 'x';
	}
	if (mask->specifier == 'i')
		mask->specifier = 'd';
}

t_printfn	get_print_fn(t_mask *mask)
{
	static t_printfn	funcs [ASCII_MAX] = {
		['d'] = ft_print_integer,
		['x'] = ft_print_hex,
		['s'] = ft_print_string,
		['u'] = ft_print_unsigned,
		['%'] = ft_print_string,
	};
	return (funcs[mask->specifier]);
}

int	ft_print_caller(t_mask *mask, va_list *arg_list, int fd)
{
	t_printfn	lcl;

	ft_polymorph(mask);
	lcl = get_print_fn(mask);
	return (lcl())
}
