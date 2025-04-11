
#include "../philo.h"

void	cleanup(t_data *d)
{
	int i = 0;
	while (i < d->cfg.nbr)
	{
		pthread_mutex_destroy(&d->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&d->print);
	free(d->forks);
	free(d->philos);
}