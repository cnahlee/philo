#include "../philo.h"

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

int	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	str_to_long(char *s, long *n)
{
	long res = 0;
	int i = 0;
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	*n = res;
	return (0);
}

int	str_to_int(char *s, int *n)
{
	long tmp;
	if (str_to_long(s, &tmp) || tmp > 2147483647)
		return (1);
	*n = (int)tmp;
	return (0);
}
