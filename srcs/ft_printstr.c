#include "ft_printfn.h"
#include "ft_supportive.h"

static void	ft_putstr_fd(const char *str, int len, int fd)
{
	write(fd, str, len);
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

static void	ft_lclprint(t_mask *mask, char *var, int len, int fd)
{
	if (mask->left_align)
	{
		if (!((mask->prec && mask->precision == 0) || *var == 0))
			ft_putstr_fd(var, len, fd);
		ft_wrap_fd(mask, fd);
	}
	else
	{
		ft_wrap_fd(mask, fd);
		if (!((mask->prec && mask->precision == 0) || *var == 0))
			ft_putstr_fd(var, len, fd);
	}
}

int	ft_print_string(t_mask *mask, va_list *arg, int fd)
{
	char	*var;
	int		len;

	var = va_arg(*arg, char *);
	if (!(var))
		var = "(null)";
	len = ft_strlen(var);
	if (mask->precision < len && mask->precision >= 0 && mask->prec)
	{
		len = mask->precision;
		mask->wrapper.sym_amnt = mask->width - mask->precision;
	}
	else
	{
		mask->wrapper.sym_amnt = mask->width - len;
	}
	ft_lclprint(mask, var, len, fd);
	if (mask->precision > len)
		return (mask->precision);
	else if (len > mask->width)
		return (len);
	else
		return (mask->width);
}
