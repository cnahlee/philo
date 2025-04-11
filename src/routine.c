#include "../philo.h"

static void	print_state(t_philo *p, char *msg)
{
	long ts;
	pthread_mutex_lock(&p->data->print);
	if (!p->data->finished)
	{
		ts = timestamp_ms() - p->data->start;
		printf("%ld %d %s\n", ts, p->id, msg);
	}
	pthread_mutex_unlock(&p->data->print);
}

static void	eat(t_philo *p)
{
	pthread_mutex_lock(p->l_fork);
	print_state(p, "has taken a fork");
	pthread_mutex_lock(p->r_fork);
	print_state(p, "has taken a fork");
	print_state(p, "is eating");
	p->last_meal = timestamp_ms();
	msleep(p->data->cfg.time_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
	p->meals++;
}

void	*philo_routine(void *arg)
{
	t_philo *p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1000);
	while (!p->data->finished)
	{
		eat(p);
		print_state(p, "is sleeping");
		msleep(p->data->cfg.time_sleep);
		print_state(p, "is thinking");
	}
	return (NULL);
}
