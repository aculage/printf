#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

//prints symbols from str up to bound or up to strlen(str)
int	ft_printcontent(const char *str, int bound, int fd)
{
	int	amnt;

	if (ft_strlen(str) < bound)
		amnt = ft_strlen(str);
	else
		amnt = bound;
	write (fd, str, amnt);
}

int	print_till_percent(const char *str, int fd)
{
	int	shft;

	shft = 0;
	while (*(str + shft) != 0 && *(str + shft) != '%')
	{
		shft++;
	}
	write(fd, str, shft);
}

//Marshals the fromat string into a structure.
void	ft_marshal_format(const char *frmt_str, t_mask *mask)
{
	
}

//Tries to find a percent sign and then call 
//a printing function and a marshaler.
//Otherwise, simply prints out the content.
int	fstr_streamline(t_mask *mask, const char *frmt_str, int fd)
{
	int	curr_pos;
	int	prev_pos;

	prev_pos = 0;
	while (*(frmt_str + curr_pos) != 0)
	{
		curr_pos = prev_pos + print_till_percent(frmt_str + prev_pos, fd);
		if (*(frmt_str + curr_pos) == '%')
		{
			ft_marshal_format(frmt_str + curr_pos, mask);
		}
		prev_pos = curr_pos;
	}
}

int ft_printf(const char *frmt_str, ...)
{
	int ret;

	va_list	arg_list;
	va_start(arg_list, frmt_str);
	ret = ft_fprintf(frmt_str, &arg_list, 1);
	va_end(arg_list);
	return(ret);
}

int	ft_fprintf(const char *frmt_str, va_list *arg_list, int fd)
{
	struct s_str_wrapper fstr_wrpr;

	fstr_interpret(fstr_interpret, format_str);
}