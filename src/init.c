#include "../philo.h"

static int	init_mutexes(t_data *d)
{
	int i = 0;
	if (pthread_mutex_init(&d->print, NULL))
		return (error_msg("mutex init\n"));
	while (i < d->cfg.nbr)
	{
		if (pthread_mutex_init(&d->forks[i], NULL))
			return (error_msg("mutex init\n"));
		i++;
	}
	return (0);
}

static void	setup_philos(t_data *d)
{
	int i = 0;
	while (i < d->cfg.nbr)
	{
		d->philos[i].id = i + 1;
		d->philos[i].meals = 0;
		d->philos[i].last_meal = timestamp_ms();
		d->philos[i].l_fork = &d->forks[i];
		d->philos[i].r_fork = &d->forks[(i + 1) % d->cfg.nbr];
		d->philos[i].data = d;
		i++;
	}
}

int	init_data(t_data *d)
{
	d->forks = malloc(sizeof(pthread_mutex_t) * d->cfg.nbr);
	d->philos = malloc(sizeof(t_philo) * d->cfg.nbr);
	if (!d->forks || !d->philos)
		return (error_msg("malloc\n"));
	if (init_mutexes(d))
		return (1);
	setup_philos(d);
	d->start = timestamp_ms();
	d->finished = 0;
	return (0);
}
