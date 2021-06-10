#include "ft_printf.h"

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

void	ft_print_caller(t_mask *mask, va_list *arg_list, int fd)
{
	ft_polymorph(mask);
	get_print_fn(mask);
}
