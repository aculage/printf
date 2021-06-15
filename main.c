#include <stdio.h>
#include "./hdrs/ft_printf.h"

int	main(void)
{
	char	*a;

	a = "abc";
	printf("%3.s", NULL);
	printf("\n");
	ft_printf("%3.s", NULL);
	return (0);
}
