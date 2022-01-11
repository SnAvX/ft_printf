
#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
        long	nb;
        int	i;

        i = 0;
        nb = n;
        if (nb > 9)
                ft_putnbr_unsigned(nb / 10);
        i += ft_putchar_fd_return((nb % 10) + '0', 1);
        return (i);
}
