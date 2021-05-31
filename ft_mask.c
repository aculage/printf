#include "ft_printf.h"
#include "libft.h"

//Extracts a decimal value.
//This is used for precision or width.
bool	extract_val(const char *str, int *shft, int *val)
{
	int	get;

	if (*str == '0')
		return (false);
	*shft = 0;
	get = 0;
	while (ft_isdigit(*(str + *shft)))
		get = get * 10 + (*(str + *shft) - '0');
}

//Extracts a flag.
//Sets it into the wrapper structure.
bool	extract_flag(const char *str, t_mask *mask)
{
	if (*str == '#')
		mask->alternative_mode = true;
	else if (*str == '-')
		mask->left_align = true;
	else if (*str == '+')
		mask->print_sign = true;
	else if (*str == ' ' && !(mask->print_sign))
		mask->frnt_spc = true;
	else if (*str == '0' && !(mask->left_align))
	{
		mask->wrapper.padding_sym = '0';
		mask->zero_padding = true;
	}
	else
		return (false);
	return (true);
}
//Extracts length modifier (e.g. l, ll, h, hh)
bool	extract_length(const char *str, int *shft, t_mask *mask)
{

}

bool	extract_specifier(const char *str, t_mask *mask)
{

}

//Marshals the fromat string into a structure.
bool	ft_marshal_format(const char *frmt_str, t_mask *mask)
{
	int	shft;
	int	add;

	shft = 1;
	while (*(frmt_str + shft) != 0)
	{
		if (extract_flag(frmt_str + shft, mask))
			shft++;
		else if (extract_val(frmt_str + shft, &add, &(mask->width)))
			shft += add;
		else if (*(frmt_str) + shft == '.')
		{
			shft++;
			extract_val(frmt_str + shft, &add, &(mask->precision));
			shft += add;
		}
		else if (extract_length(frmt_str + shft, &add, mask))
			shft += add;
		else if (extract_specifier(frmt_str + shft, mask))
			return (true);
	}
	return (false);
}
