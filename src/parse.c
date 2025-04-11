#include "../philo.h"

static int	check_digits(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	parse_args(t_cfg *cfg, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (error_msg("invalid arg count\n"));
	if (check_digits(av[1]) || check_digits(av[2]) ||
		check_digits(av[3]) || check_digits(av[4]) ||
		(ac == 6 && check_digits(av[5])))
		return (error_msg("non‑numeric arg\n"));
	if (str_to_int(av[1], &cfg->nbr) || cfg->nbr <= 0 || cfg->nbr > 200)
		return (error_msg("bad nbr\n"));
	if (str_to_long(av[2], &cfg->time_die) || cfg->time_die < 0)
		return (error_msg("bad time\n"));
	if (str_to_long(av[3], &cfg->time_eat) || cfg->time_eat < 0)
		return (error_msg("bad time\n"));
	if (str_to_long(av[4], &cfg->time_sleep) || cfg->time_sleep < 0)
		return (error_msg("bad time\n"));
	cfg->must_eat = -1;
	if (ac == 6 && (str_to_int(av[5], &cfg->must_eat) || cfg->must_eat <= 0))
		return (error_msg("bad must_eat\n"));
	return (0);
}