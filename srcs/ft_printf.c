#include <stdlib.h>
#include "ft_printf.h"
#include <stdarg.h>
#include "ft_supportive.h"

int	print_till_percent(t_mask *mask, const char *str, int fd)
{
	int	shft;

	shft = 0;
	while (*(str + shft) != 0 && *(str + shft) != '%')
	{
		shft++;
	}
	mask->symbols_printed += shft;
	write(fd, str, shft);
	return (shft);
}

//Tries to find a percent sign and then call 
//a printing function and a marshaler.
//Otherwise, simply prints out the content.
int	fstr_streamline(
	t_mask *mask, const char *frmt_str, va_list *arg_list, int fd)
{
	int	curr_pos;
	int	prev_pos;
	int	shft;

	prev_pos = 0;
	curr_pos = 0;
	while (*(frmt_str + curr_pos) != 0)
	{
		curr_pos = prev_pos + print_till_percent(mask, frmt_str + prev_pos, fd);
		if (*(frmt_str + curr_pos) == '%')
		{
			init_mask(mask);
			shft = ft_marshal_format(frmt_str + curr_pos, mask, arg_list);
			if (shft > 0)
			{
				curr_pos += shft;
				ft_print_caller(mask, arg_list, fd);
			}
			else
				return (0);
		}
		prev_pos = curr_pos;
	}
	return (0);
}

int32_t	ft_fprintf(const char *frmt_str, va_list *arg_list, int fd)
{
	t_mask	fstr_wrpr;

	(void) arg_list;
	fstr_wrpr.symbols_printed = 0;
	fstr_streamline(&fstr_wrpr, frmt_str, arg_list, fd);
	return (fstr_wrpr.symbols_printed);
}

int	ft_printf(const char *frmt_str, ...)
{
	int		ret;
	va_list	arg_list;

	va_start(arg_list, frmt_str);
	ret = ft_fprintf(frmt_str, &arg_list, 1);
	va_end(arg_list);
	return (ret);
}
