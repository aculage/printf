#include <stdio.h>
#include "./hdrs/ft_printf.h"

int	main(void)
{
	int	a;

	a = 121212;
	printf("%7d", -54);
	printf("\n");
	ft_printf("%7d", -54);
	printf("\nUWOTM8\n");
	printf("%07d", -54);
	printf("\n");
	ft_printf("%07d", -54);
	printf("\nUWOTM8\n");
	printf("%.7d", -54);
	printf("\n");
	ft_printf("%.7d", -54);
	return (0);
}
