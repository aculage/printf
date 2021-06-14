#include "ft_printf.h"
#include "ft_supportive.h"

static int	ft_numlen(long long in)
{
	int	cnt;

	if (in == 0)
		return (1);
	cnt = 0;
	while (in != 0)
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
	else
	{
		write(fd, "-", 1);
		return ;
	}
}

static void	ft_wrap_fd(t_mask *mask, int fd, bool flag)
{
	int	cnt;

	cnt = 0;
	if (flag)
	{
		if (mask->prec)
			mask->wrapper.padding_sym = ' ';
		while (cnt < mask->wrapper.sym_amnt)
		{
			write(fd, &(mask->wrapper.padding_sym), 1);
			cnt++;
		}
	}
	if (!flag)
	{
		while (cnt < mask->wrapper.pr_sym_amnt)
		{
			write(fd, "0", 1);
			cnt++;
		}
	}
}

static void	ft_lclprint(t_mask *mask, int var, int fd)
{
	if (!(mask->prec)
		&& mask->wrapper.padding_sym == '0' && !(mask->left_align))
	{
		ft_printsign_fd(mask, var, fd);
		ft_wrap_fd(mask, fd, true);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_fd(var, fd);
	}
	else if (mask->left_align)
	{
		ft_printsign_fd(mask, var, fd);
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_fd(var, fd);
		ft_wrap_fd(mask, fd, true);
	}
	else
	{
		ft_wrap_fd(mask, fd, true);
		ft_printsign_fd(mask, var, fd);
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_fd(var, fd);
	}
}

int	ft_print_integer(t_mask *mask, va_list *arg, int fd)
{
	int	var;
	int	len;
	int	sgn;

	var = va_arg(*arg, int);
	len = ft_numlen(var);
	sgn = 0;
	if (mask->prec && mask->precision == 0 && var == 0)
		len = 0;
	if (mask->print_sign || var < 0 || mask->frnt_spc)
		sgn = 1;
	mask->wrapper.pr_sym_amnt = mask->precision - len;
	if (mask->wrapper.pr_sym_amnt > 0)
		mask->wrapper.sym_amnt = mask->width - mask->precision - sgn;
	else
		mask->wrapper.sym_amnt = mask->width - len - sgn;
	ft_lclprint(mask, var, fd);
	if (mask->precision > len)
		return (mask->precision);
	else if (len > mask->width)
		return (len);
	else
		return (mask->width);
}
