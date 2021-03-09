#include "libft.h"

int	ft_isspace(int c)
{
	if ((8 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}
