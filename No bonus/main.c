#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%p %d %s %s %c\n", malloc, -47, "test", "sa", 'c');
	ft_printf("%p %d %s %s %c\n", malloc, -47, "test", "sa", 'c');
}
