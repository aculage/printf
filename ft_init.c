#include "ft_printf.h"

void	init_mask(t_mask *mask)
{
	mask->alternative_mode = false;
	mask->frnt_spc = false;
	mask->left_align = false;
	mask->symbols_printed = 0;
	mask->width = 0;
	mask->precision = 0;
	mask->specifier = 0;
	mask->uppercase = 0;
	init_wrapper(&(mask->wrapper));
	init_length(&(mask->length));
}

void	init_wrapper(t_wrapper *wrapper)
{
	wrapper->b_sym_amnt = 0;
	wrapper->f_sym_amnt = 0;
	wrapper->padding_sym = ' ';
	wrapper->sign[0] = 0;
	wrapper->sign[1] = 1;
}

void	init_length(t_length *length)
{
	length->h = false;
	length->hh = false;
	length->l = false;
	length->ll = false;
}

