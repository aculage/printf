#include "ft_printf.h"
#include "ft_printfn.h"

void	ft_putchar_fd(char var, int fd)
{
	write(fd, &var, fd);
}

static void	ft_wrap_fd(t_mask *mask, int fd)
{
	int	cnt;

	cnt = 0;
	if (mask->prec)
		mask->wrapper.padding_sym = ' ';
	while (cnt < mask->wrapper.sym_amnt)
	{
		write(fd, &(mask->wrapper.padding_sym), 1);
		cnt++;
	}
}

static void	ft_lclprint(t_mask *mask, char var, int fd)
{
	if (mask->left_align)
	{
		ft_putchar_fd(var, fd);
		ft_wrap_fd(mask, fd);
	}
	else
	{
		ft_wrap_fd(mask, fd);
		ft_putchar_fd(var, fd);
	}
}

int	ft_print_percent(t_mask *mask, va_list *arg, int fd)
{
	char	var;

	(void) arg;
	var = '%';
	mask->wrapper.sym_amnt = mask->width - 1;
	ft_lclprint(mask, var, fd);
	if (mask->width > 0)
		return (mask->symbols_printed += mask->width);
	else
		return (mask->symbols_printed += 1);
}

int	ft_print_char(t_mask *mask, va_list *arg, int fd)
{
	char	var;

	var = (char)va_arg(*arg, int);
	mask->wrapper.sym_amnt = mask->width - 1;
	ft_lclprint(mask, var, fd);
	if (mask->width > 0)
		mask->symbols_printed += mask->width;
	else
		mask->symbols_printed += 1;
	return (1);
}
