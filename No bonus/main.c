#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str[] = "test";
	printf("%p %d %s %s %c\n", str, -47, "test", "sa", 'c');
	ft_printf("%p %d %s %s %c\n", str, -47, "test", "sa", 'c');
}
