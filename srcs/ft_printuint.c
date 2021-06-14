#include "ft_printf.h"
#include "libft.h"

static int	ft_numlen(long long in)
{
	int	cnt;

	cnt = 0;
	while (in > 0)
	{	
		in /= 10;
		cnt++;
	}
	return (cnt);
}

static void	ft_printsign_fd(t_mask *mask, int var, int fd)
{
	if (var >= 0)
	{
		if (mask->print_sign)
		{
			write(fd, "+", 1);
			return ;
		}
		if (mask->frnt_spc)
		{
			write(fd, " ", 1);
			return ;
		}
	}
}

static void	ft_wrap_fd(t_mask *mask, int fd)
{
	int	cnt;

	cnt = 0;
	while (cnt < mask->wrapper.sym_amnt)
	{
		write(fd, mask->wrapper.padding_sym, 1);
	}
}

static void	ft_lclprint(t_mask *mask, long long len, int var, int fd)
{
	if (mask->left_align)
	{
		ft_printsign_fd(mask, var, fd);
		ft_putnbr_fd(var, fd);
		ft_wrap_fd(mask, fd);
	}
	else
	{
		ft_wrap_fd(mask, fd);
		ft_printsign_fd(mask, var, fd);
		ft_putnbr_fd(var, fd);
	}
}

void	ft_print_integer(t_mask *mask, va_list *arg, int fd)
{
	int	var;
	int	len;

	var = va_arg(*arg, int);
	len = ft_numlen(var);
	if (mask->print_sign || var < 0 || mask->frnt_spc)
		len++;
	if (len < mask->precision || mask->precision == 0)
		mask->wrapper.sym_amnt = mask->width - len;
	else
		mask->wrapper.sym_amnt = mask->width - mask->precision;
	ft_lclprint(mask, len, var, fd);
	if (mask->precision > len)
		return (mask->precision);
	else if (len > mask->width)
		return (len);
	else
		return (mask->width);
}
