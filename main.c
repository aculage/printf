#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int a;
    
    a = 121212;
    printf("%-12.5d", a);
	ft_printf("%-*.*d", 5, 10, a);	
    return 0;
}
