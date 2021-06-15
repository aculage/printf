#include <stdio.h>
#include <limits.h>
#include "./hdrs/ft_printf.h"

int	main(void)
{
	char	*a;

	a = "abc";
	int g = printf(" *%-*.*x* *%*.*x* ", 4, 5, 10, 10, 21, -10);
	printf("\n");
	int z = ft_printf(" *%-*.*x* *%*.*x* ", 4, 5, 10, 10, 21, -10);
	(void) z;
	return (0);
}
