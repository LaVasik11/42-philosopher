#include "philo.h"

void	initphilos(t_engine *engine, t_philo *philos, t_mut *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].philo_count = ft_atoi(argv[1]);
		philos[i].times.die = ft_atoi(argv[2]);
		philos[i].times.eat = ft_atoi(argv[3]);
		philos[i].times.sleep = ft_atoi(argv[4]);
		philos[i].times.last_meal = get_current_time();
		philos[i].times.born_time = get_current_time();
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].meals_eaten = 0;
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &engine->write_lock;
		philos[i].mutexes.meal_lock = &engine->meal_lock;
		i++;
	}
}

void	init_forks(t_mut *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
		pthread_mutex_init(&forks[i++], NULL);
}

void	init_engine(t_engine *engine, t_philo *philos, t_mut *forks)
{
	engine->forks = forks;
	engine->philos = philos;
	pthread_mutex_init(&engine->write_lock, NULL);
	pthread_mutex_init(&engine->meal_lock, NULL);
}
