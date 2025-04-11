#include"../philo.h"
static int	start_simulation(t_data *d)
{
	int i = 0;
	while (i < d->cfg.nbr)
	{
		if (pthread_create(&d->philos[i].thread, NULL,
			&philo_routine, &d->philos[i]))
			return (error_msg("pthread_create failed\n"));
		i++;
	}
	monitor(d);
	i = 0;
	while (i < d->cfg.nbr)
	{
		pthread_join(d->philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data d;

	if (parse_args(&d.cfg, argc, argv))
		return (1);
	if (init_data(&d))
		return (1);
	if (start_simulation(&d))
		return (1);
	cleanup(&d);
	return (0);
}

