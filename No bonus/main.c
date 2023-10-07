#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%p %d %s %s %c\n", malloc, -47, "tes", "sa", 'c');
	ft_printf("%p %d %s %s %c\n", malloc, -47, "test", "sa", 'c');
	printf("\n%d", ft_putnbr_long(4774));
}	