#include "philo.h"

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error();
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			ft_error();
		else if (i == 5 && (num < 0 || num > INT_MAX))
			ft_error();
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			ft_error();
	}
}

int	main(int argc, char **argv)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mut		forks[PHILO_MAX_COUNT];
	t_engine	engine;

	check_args(argc, argv);
	init_engine(&engine, philos, forks);
	init_forks(forks, ft_atoi(argv[1]));
	initphilos(&engine, philos, forks, argv);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, philos[0].philo_count);
	return (0);
}
