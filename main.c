#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int a;
    
    a = 121212;
    printf("%-12.5d", a);
	ft_printf("%-12.5d", a);	
    return 0;
}
