#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		devaluator;
	char	minus;
	char	num;
	char	flag;

	devaluator = 1000000000;
	flag = 0;
	minus = '-';
	if (n > 0)
		n = -n;
	while (devaluator > 0)
	{
		num = -(n / devaluator % 10);
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

int	ft_isdigit(int ch)
{
	if ((ch >= 48) && (ch <= 57))
		return (ch);
	return (0);
}

char	*ft_strchr( const char *string, int symbol )
{
	size_t	cnt;

	cnt = 0;
	while (*(string + cnt) != 0)
	{
		if (symbol == *(string + cnt))
			return ((char *)string + cnt);
		cnt++;
	}
	if (symbol == *(string + cnt))
		return ((char *)string + cnt);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt) != 0)
	{
		cnt++;
	}
	return (cnt);
}
