#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int a;
    
    a = 121212;
    printf("%--*.*d",5, 10,  a);
	ft_printf("%0*.*d", 5, 10, a);	
    return 0;
}
