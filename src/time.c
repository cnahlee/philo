#include "../philo.h"

long	timestamp_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	msleep(long ms)
{
	long target = timestamp_ms() + ms;
	while (timestamp_ms() < target)
		usleep(500);
}