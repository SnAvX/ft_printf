#include "libft.h"

int	ft_putchar_fd_return(char c, int fd)
{
	int	i;

	i = 0;
	write(fd, &c, 1);
	i++;
	return (i);
}
