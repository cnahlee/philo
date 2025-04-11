#include "../philo.h"

static int	check_death(t_data *d, int i)
{
	long now = timestamp_ms();
	if (now - d->philos[i].last_meal > d->cfg.time_die)
	{
		pthread_mutex_lock(&d->print);
		printf("%ld %d died\n", now - d->start, d->philos[i].id);
		d->finished = 1;
		pthread_mutex_unlock(&d->print);
		return (1);
	}
	return (0);
}

static int	all_ate(t_data *d)
{
	int i = 0;
	if (d->cfg.must_eat <= 0)
		return (0);
	while (i < d->cfg.nbr)
	{
		if (d->philos[i].meals < d->cfg.must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	monitor(t_data *d)
{
	int i;
	while (!d->finished)
	{
		i = 0;
		while (i < d->cfg.nbr && !d->finished)
		{
			if (check_death(d, i))
				break ;
			i++;
		}
		if (all_ate(d))
			d->finished = 1;
		usleep(1000);
	}
}
