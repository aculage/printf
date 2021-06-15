#include "ft_printf.h"

static void	init_wrapper(t_wrapper *wrapper)
{
	wrapper->sym_amnt = 0;
	wrapper->padding_sym = ' ';
	wrapper->pr_sym_amnt = 0;
	wrapper->sign[0] = 0;
	wrapper->sign[1] = 1;
}

static void	init_length(t_length *length)
{
	length->h = false;
	length->hh = false;
	length->l = false;
	length->ll = false;
}

void	init_mask(t_mask *mask)
{
	mask->alternative_mode = false;
	mask->frnt_spc = false;
	mask->left_align = false;
	mask->print_sign = false;
	mask->prec = false;
	mask->width = 0;
	mask->precision = 0;
	mask->specifier = 0;
	mask->uppercase = 0;
	init_wrapper(&(mask->wrapper));
	init_length(&(mask->length));
}
