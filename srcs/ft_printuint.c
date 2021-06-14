#include "ft_printf.h"
#include "ft_supportive.h"

static int	ft_numlen(long long in)
{
	int	cnt;

	if (in == 0)
		return (1);
	cnt = 0;
	while (in > 0)
	{	
		in /= 10;
		cnt++;
	}
	return (cnt);
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

void	ft_putuint_fd(unsigned int n, int fd)
{
	int		devaluator;
	char	num;
	char	flag;

	devaluator = 1000000000;
	flag = 0;
	while (devaluator > 0)
	{
		num = n / devaluator % 10;
		if ((num > 0 || flag > 0) || (devaluator == 1))
		{
			flag = 1;
			num += 48;
			write(fd, &num, 1);
			n %= devaluator;
		}
		devaluator /= 10;
	}
}

static void	ft_lclprint(t_mask *mask, unsigned int var, int fd)
{
	if (mask->left_align)
	{
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putuint_fd(var, fd);
		ft_wrap_fd(mask, fd, true);
	}
	else
	{
		ft_wrap_fd(mask, fd, true);
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putuint_fd(var, fd);
	}
}

int	ft_print_unsigned(t_mask *mask, va_list *arg, int fd)
{
	unsigned int	var;
	int				len;

	var = va_arg(*arg, int);
	len = ft_numlen(var);
	if (mask->prec && mask->precision == 0 && var == 0)
		len = 0;
	mask->wrapper.pr_sym_amnt = mask->precision - len;
	if (mask->wrapper.pr_sym_amnt > 0)
		mask->wrapper.sym_amnt = mask->width - mask->precision;
	else
		mask->wrapper.sym_amnt = mask->width - len;
	ft_lclprint(mask, var, fd);
	if (mask->precision > len)
		return (mask->precision);
	else if (len > mask->width)
		return (len);
	else
		return (mask->width);
}
