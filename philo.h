#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_cfg
{
	int		nbr;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	int		must_eat;
}t_cfg;

struct s_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;
}t_philo;

/* ---------------------- SHARED --------------------- */
typedef struct s_data
{
	t_cfg			cfg;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	long			start;
	int				finished;
}t_data;

/* ------------- PROTOTYPES ------------------------- */
/* parse.c */
int		parse_args(t_cfg *cfg, int ac, char **av);
/* init.c */
int		init_data(t_data *d);
/* routine.c */
void	*philo_routine(void *arg);
/* monitor.c */
void	monitor(t_data *d);
/* utils.c */
int		error_msg(char *msg);
int		str_to_int(char *s, int *n);
int		str_to_long(char *s, long *n);
size_t	ft_strlen(const char *s);
/* time.c */
long	timestamp_ms(void);
void	msleep(long ms);
/* cleanup.c */
void	cleanup(t_data *d);

#endif