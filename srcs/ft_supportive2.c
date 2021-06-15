#include "ft_printf.h"
#include <unistd.h>
#include "ft_supportive.h"

void	ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd)
{
	long long	bs;
	char		buf[35];
	int			ll;

	ll = 0;
	bs = ft_strlen(base);
	if (nbr == 0)
		write(1, base, 1);
	while (nbr > 0)
	{
		buf[ll] = base[(nbr % bs)];
		nbr /= bs;
		ll++;
	}
	while (ll > 0)
	{
		ll--;
		write(fd, &buf[ll], 1);
	}
}

void	extract_star(t_mask *mask, va_list *arg_list, int *val, int *shft)
{
	*val = va_arg(*arg_list, int);
	if (*val < 0)
	{
		mask->left_align = true;
		*val *= -1;
	}
	(*shft)++;
}

int32_t	ft_max3(int32_t a, int32_t b, int32_t c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

int32_t	ft_min(int32_t a, int32_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int32_t	ft_max(int32_t a, int32_t b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
