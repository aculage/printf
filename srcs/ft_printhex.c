#include "ft_supportive.h"
#include "ft_printf.h"

static int	ft_numlen(unsigned long long in)
{
	int	cnt;

	if (in == 0)
		return (1);
	cnt = 0;
	while (in != 0)
	{	
		in /= 16LL;
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
		if (mask->prec || mask->left_align)
			mask->wrapper.padding_sym = ' ';
		while (cnt < mask->wrapper.sym_amnt)
		{
			write(fd, &(mask->wrapper.padding_sym), 1);
			cnt++;
		}
	}
	if (!flag)
	{
		if (mask->alternative_mode)
			write(fd, "0x", 2);
		while (cnt < mask->wrapper.pr_sym_amnt)
		{
			write(fd, "0", 1);
			cnt++;
		}
	}
}

static void	ft_lclprint(t_mask *mask, unsigned long long var,
							char *base, int fd)
{
	if (!(mask->prec)
		&& mask->wrapper.padding_sym == '0' && !(mask->left_align))
	{
		ft_wrap_fd(mask, fd, true);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_base_fd(var, base, fd);
	}
	else if (mask->left_align)
	{
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_base_fd(var, base, fd);
		ft_wrap_fd(mask, fd, true);
	}
	else
	{
		ft_wrap_fd(mask, fd, true);
		ft_wrap_fd(mask, fd, false);
		if (!(mask->prec && mask->precision == 0 && var == 0))
			ft_putnbr_base_fd(var, base, fd);
	}
}

int	ft_print_hex(t_mask *mask, va_list *arg, int fd)
{
	unsigned long long	var;
	int					len;

	var = (unsigned) va_arg(*arg, void *);
	len = ft_numlen(var);
	if (mask->prec && mask->precision == 0 && var == 0)
		len = 0;
	if (mask->alternative_mode)
		len += 2;
	mask->wrapper.pr_sym_amnt = mask->precision - len;
	if (mask->wrapper.pr_sym_amnt > 0)
		mask->wrapper.sym_amnt = mask->width - mask->precision;
	else
		mask->wrapper.sym_amnt = mask->width - len;
	if (mask->uppercase)
		ft_lclprint(mask, var, "0123456789ABCDEF", fd);
	else
		ft_lclprint(mask, var, "0123456789abcdef", fd);
	if (mask->width > (ft_max(mask->precision, len)))
		mask->symbols_printed += mask->width;
	else
		mask->symbols_printed += ((ft_max(mask->precision, len)));
	return (1);
}
